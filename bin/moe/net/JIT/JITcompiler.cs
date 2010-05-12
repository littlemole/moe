using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Reflection;
using System.CodeDom;
using System.CodeDom.Compiler;
using System.Windows.Forms;
using Microsoft.JScript;
using System.Runtime.InteropServices;

namespace mol
{
    // compile C#, VB and JScipt.NET on the fly
    [ComVisible(false)]
    public class JITcompiler  : MarshalByRefObject
    {

        public JITcompiler()
        {
            //location = Path.GetDirectoryName(typeof(JITcompiler).Assembly.Location);
            compilerparams.GenerateInMemory   = true;
            compilerparams.GenerateExecutable = true;
        }

        //accessors

        public bool GenerateExecutable
        {
            get { return compilerparams.GenerateExecutable;  }
            set { compilerparams.GenerateExecutable = value; }
        }

        public bool GenerateInMemory
        {
            get { return compilerparams.GenerateInMemory;  }
            set { compilerparams.GenerateInMemory = value; }
        }

        public bool DebugInfo
        {
            get { return compilerparams.IncludeDebugInformation; }
            set { compilerparams.IncludeDebugInformation = value; }
        }

        public bool Omptimize
        {
            get { return optimize; }
            set { optimize = value; }
        }

        public bool Win32Target
        {
            get { return win32target; }
            set { win32target = value; }
        }

        public string AssemblyName
        {
            get { return assemblyName;  }
            set { assemblyName = value; }
        }

        public string Options
        {
            get { return options; }
            set { options = value; }
        }

        public void AddDirectory(string dir)
        {
            directories.Add(dir);
        }
        
        public void ClearDirectories()
        {
            directories.Clear();
        }

        public void AddSourceText(string txt)
        {
            sources.Add(txt);
        }

        public void AddSourceFile(string f)
        {
            sourcefiles.Add(f);
        }

        public void ClearSources()
        {
            sources.Clear();
            sourcefiles.Clear();
        }

        public void AddReference(string r)
        {
            references.Add(r);
        }

        public void ClearReferences()
        {
            references.Clear();
        }

        public bool OutOfSync(DateTime date)
        {
            if (sourcefiles.Count < 1)
                return true;

            foreach (string s in sourcefiles)
            {
                DateTime src_date = File.GetLastWriteTime(s);
                if (src_date > date)
                    return true;
            }
            return false;
        }

        // determine success
        public bool Success
        {
            get
            {
                if ( results != null)
                    if (!results.Errors.HasErrors)
                        if (results.CompiledAssembly != null)
                            return true;
                return false;
            }
        }

        // compile some .NET source     
        public void compile( IScriptCallback cb )
        {
            // get provider for language
            provider = codeProvider();

            // only if non-in-memory build
            if (assemblyName != null && !assemblyName.Equals(""))
            {
                compilerparams.GenerateInMemory = false;
                compilerparams.OutputAssembly   = this.AssemblyName;

                //if (compilerparams.GenerateExecutable)
                //    compilerparams.OutputAssembly += ".exe";
                //else
                //    compilerparams.OutputAssembly += ".dll";
            }

            // options
            compilerparams.CompilerOptions = "/lib:\"" + Path.GetDirectoryName(assemblyName)+"\" ";

            string piop = System.Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles)
                        + "\\Microsoft.NET\\Primary Interop Assemblies";

            compilerparams.CompilerOptions += "/lib:\"" + piop + "\" ";

            foreach (string d in directories)
            {
                compilerparams.CompilerOptions += "/lib:\"" + d +"\" ";
            }

            if ( this.win32target )
                compilerparams.CompilerOptions += " /target:winexe ";

            if (this.Omptimize )
                compilerparams.CompilerOptions += " /optimize ";

            compilerparams.CompilerOptions += options;

            // add source comment References to DLLs
            if (this.sourcefiles.Count > 0)
            {
            }
            else
                addReferences(sources.ToArray());

            // add explicit references 
            foreach (string r in this.references )
                compilerparams.ReferencedAssemblies.Add(r);

            // default lib references
            compilerparams.ReferencedAssemblies.Add("System.dll");

            string mshtml = piop + "\\Microsoft.mshtml.dll";
            string stdole = piop + "\\stdole.dll";

            compilerparams.ReferencedAssemblies.Add(mshtml);
            compilerparams.ReferencedAssemblies.Add(stdole);

            compilerparams.ReferencedAssemblies.Add("System.Windows.Forms.dll");
            compilerparams.ReferencedAssemblies.Add("System.Drawing.dll");

            // add reference to self
            compilerparams.ReferencedAssemblies.Add(this.GetType().Assembly.Location);

            // actually compile
            if ( this.sourcefiles.Count > 0 )
                results = provider.CompileAssemblyFromFile(compilerparams, this.sourcefiles.ToArray());
            else
                results = provider.CompileAssemblyFromSource(compilerparams, this.sources.ToArray());

            // check compilation results
            if (results.Errors.HasErrors)
            {
                System.Text.StringBuilder sb = new System.Text.StringBuilder();

                foreach (CompilerError error in results.Errors)
                {
                    if ( error.IsWarning )
                        sb.Append("Warning: ");
                    else
                        sb.Append("Error: ");

                    sb.Append(error.ErrorNumber);
                    sb.Append(" in ");
                    sb.Append(error.FileName);
                    sb.Append(" line: ");
                    sb.Append(error.Line.ToString());
                    sb.Append("\r\n");
                    sb.Append(error.ErrorText);
                    sb.Append("\r\n");
                }
                cb.OnCompilerError(sb.ToString());
                return;
            }
        }

        public void execute()
        {
            if (this.assemblyName != null && !this.assemblyName.Equals(""))
            {
                execAssembly(this.assemblyName);
                return;
            }

            if (results.Errors.HasErrors)
                return;

            if (results.CompiledAssembly == null)
                return;

            // if we got here we have a successfull build
            // run and execute the main entry point

            // we pass empty arguments to "Entrypoint::main"
            object[] empty = new object[] { null };

            // don't ask! JS wants to be handled that way
            //if (lang.Equals("js"))
            //empty = new object[] { null };

            //string[] empty = new string[] { null };

            // execute and run!
            results.CompiledAssembly.EntryPoint.Invoke(null, BindingFlags.Static | BindingFlags.FlattenHierarchy, null, empty, null);
        }


        // execute Assembly
        public void execAssembly(string name)
        {
            //Assembly a = Assembly.LoadFile(name);
            
            AssemblyName an = System.Reflection.AssemblyName.GetAssemblyName(name);

            Assembly a = System.AppDomain.CurrentDomain.Load(an); 


            // we pass empty arguments to "Entrypoint::main"
            object[] empty = new object[] { };

            // execute and run!
            a.EntryPoint.Invoke(null, BindingFlags.Static | BindingFlags.FlattenHierarchy, null, empty, null);
        }


        // helper to add DLL references
        private void addReferences(string[] sources)
        {
            foreach (string src in sources)
            {
                using (StringReader reader = new StringReader(src))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        Match m = Regex.Match(line, "(//|') ?@ref: ?([^\r\n\t]*)");
                        if (m.Success)
                        {
                            compilerparams.ReferencedAssemblies.Add(m.Groups[2].Value);
                            continue;
                        }
                        m = Regex.Match(line, "(//|') ?@lang: ?([^\r\n\t]*)");
                        if (m.Success)
                        {
                            continue;
                        }
                        break;
                    }
                }
            }
        }

        // CodeDomProvider factory
        private CodeDomProvider codeProvider()
        {
            if (this.sourcefiles.Count > 0)
            {
                lang = System.IO.Path.GetExtension(this.sourcefiles[0]).Substring(1);
            }        
            else
            if (this.sources.Count > 0)
            {
                string src = this.sources[0];

                using (StringReader reader = new StringReader(src))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        Match m = Regex.Match(line, "(//|') ?@lang: ?([^\r\n\t]*)");
                        if (m.Success)
                        {
                            lang = m.Groups[2].Value;
                        }
                        m = Regex.Match(line, "(//|') ?@ref: ?([^\r\n\t]*)");
                        if (m.Success)
                        {
                            continue;
                        }
                        break;
                    }
                }
            }


            CodeDomProvider provider;
            switch (lang)
            {
                case "cs":
                    provider = new Microsoft.CSharp.CSharpCodeProvider();
                    break;
                case "vb":
                    provider = new Microsoft.VisualBasic.VBCodeProvider();
                    break;
                case "js":
                    provider = new Microsoft.JScript.JScriptCodeProvider();
                    break;
                default:
                    throw new Exception(lang);
            }
            return provider;
        }

        //compiler
        private CodeDomProvider provider;
        private CompilerParameters compilerparams = new CompilerParameters();
        private CompilerResults results;

        // build settings
        private string lang = "cs";
        private string assemblyName;
        private string options;
        private bool optimize = false;
        private bool win32target = false;

        // include dirs
        private List<string> directories = new List<string>();

        // sources
        private List<string> sources = new List<string>();

        // source files
        private List<string> sourcefiles = new List<string>();

        // references
        private List<string> references = new List<string>();
    }
}
