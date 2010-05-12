//@ref:System.Web.dll
//@ref:moe.dll
 
using mshtml;
using System.Windows.Forms;
using System.Text.RegularExpressions;
using System.Web;
using System.IO;
using System.Threading;
using mol; 
    
// codebehind for grep.html

public class MyGrepBehind : CodeBehind
{
	private string path;
	private string pattern;
	private bool filesOnly;
	private bool subDirs;
	private	Thread t = null;

	public MyGrepBehind()
	{
	  // init js libs
	  eval( "setupPanes( 'container', 'defaultTab' )");
	  eval( "draggable( 'tabs' )");
 	}

    // cleanup
    public override void unload()
    {}

	// Script main entry point
    public static void Main() 
    {
		MyGrepBehind grep = new MyGrepBehind();
        Application.Run();
    }

	// called from generated javascript in
	// dynamic HTML Output - opens link in editor
	public void JumpTo( string file )
	{ 
		Moe.IDoc d = (Moe.IDoc)moe.Docs.Item(file);
		if (d == null)
		{
		   d = (Moe.IDoc)moe.Open(file);
		}
		if (d == null)
		  return;
	
		d.Activate();
	}

	// abort called when user cancelled a grep
	private void abort()
	{ 
		this.t.Abort();
		this["results"].innerHTML += "<br>aborted";
		this["grep"].innerHTML = "grep";
	}

	// event handler - user clicked choose folder button
	[HTMLEventHandler(typeof(HTMLButtonElementEvents_Event))]
	public bool folder_onclick( IHTMLEventObj e)
	{
        // Show the FolderBrowserDialog.
		FolderBrowserDialog folderBrowserDlg = new FolderBrowserDialog();
		folderBrowserDlg.Description = "Choose Folder to GREP for";
        DialogResult result = folderBrowserDlg.ShowDialog();
        if( result == DialogResult.OK )
        {
            string folderName = folderBrowserDlg.SelectedPath;
			node<IHTMLInputElement>("path").value = folderName;
        }
		return false;
	}

	// event handler - we grep when button clicked
	[HTMLEventHandler(typeof(HTMLButtonElementEvents_Event))]
	public bool grep_onclick( IHTMLEventObj e)
	{
		if ( t != null )
		if ( t.IsAlive )
		{
            // user cancelled
			abort();
			return true;
		}

		// retrive data from HTML form
		this.path      = ((IHTMLInputElement)this["path"]).value;
		this.pattern   = ((IHTMLInputElement)this["what"]).value;
		this.filesOnly = ((IHTMLInputElement)this["filesonly"]).@checked;
		this.subDirs   = ((IHTMLInputElement)this["subdirs"]).@checked;

		// setup cancel button
		this["grep"].innerHTML = "cancel";

		t = new Thread(this.grep);
		t.SetApartmentState(ApartmentState.STA);
		t.Start();

		return false;
	}

	// main grep thread entry point
	public void grep()
	{
		if ( !System.IO.Directory.Exists(path) )
		  return;

		this["results"].innerHTML = grepDir(path);
		this["grep"].innerHTML = "grep";	 
    }

	// recursive grep workhorse
	public string grepDir( string dir )
	{
		string oss = "";

		try 
		{
			if ( !System.IO.Directory.Exists(dir) )
				return "";

			string[] files = System.IO.Directory.GetFiles(dir);
		
			if ( files != null )
			for ( int i = 0; i< files.Length; i++ )
			{
				if ( files[i] == null )
					continue;
				if (!System.IO.File.Exists(files[i]))
					continue;
				FileInfo fi = new FileInfo(files[i]);
				if ( fi.Length > 3145728 )
					continue;
		
				string where = "grepping " + System.IO.Path.GetDirectoryName(files[i]);
				where += "<br><hr><br>" + System.IO.Path.GetFileName(files[i]);
		
				this["results"].innerHTML = where;
				
				string line = "";
				
				System.IO.StreamReader reader 
						= new System.IO.StreamReader(files[i]);
					
				bool firstHit = true;
				int l = 0;
		
				while (reader.Peek() >= 0) 
				{
					line = reader.ReadLine();
								
					Regex r = new Regex ( pattern );
					Match m = r.Match( line );
					while (m.Success)
					{
						string f = files[i].Replace("\\","\\\\");
						string n = Path.GetFileName(f);
						if (firstHit)
						{
							oss += "<div style='margin-top:2px;margin-bottom:2px;' class='moe'><a class='moe' href='#result' ";
							oss += "onClick=\"external.Code.JumpTo('";
							oss += f + "');\" title='" + files[i] + "'>";
							oss += "<small><b>" + n + "</b></small></a>";
							oss += "</div>";
							firstHit = false;
						}
				
						if ( this.filesOnly )
						  break;
		
					    string hit = m.Value;
					
						oss += "<div style='margin:0px;padding-bottom:3px'><b> line " + l + ":</b> ";
						oss += HttpUtility.HtmlEncode(line);
						oss += "</div><br>";
						   
						m = m.NextMatch();
					} // end while match
				
					l++;
					if ( this.filesOnly && !firstHit )
					    break;		
				} // end while reader.peek
			}//end for i

			if ( this.subDirs == true )
			{
				string[] dirs = System.IO.Directory.GetDirectories(dir);	
				foreach ( string d in dirs )
					grepDir(d);
			}
		} 	
		catch( System.Exception e) 
		{
			MessageBox.Show(e.Message);
		}
		return oss;
	}
}
