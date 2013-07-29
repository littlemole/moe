var path = new ActiveXObject("IO.Path");
var diff = new ActiveXObject("IO.UniDiff");

var source = "";

var fha = path.OpenFile(ActiveDoc.Filepath);
if ( fha ) {
  source = fha.ReadText();
  fha.Close();
}

var modified = ActiveDoc.Object.Text.Value;

var df  = "--- " + ActiveDoc.Filepath + " (original)\r\n";  
    df += "+++ " + ActiveDoc.Filepath + " (modified)\r\n";  

df += diff.Diff(source,modified);

var d = Documents.New();
d.Object.Text.SetText(df);

