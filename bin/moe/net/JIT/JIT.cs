using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Reflection;
using System.Runtime.Remoting;
using System.Runtime.InteropServices;
using System.Threading;

/*
 * usage model:
 * 
 * new compiler
 *  Start----------------+
 *   AddReferences  --+  |
 *   AddSources       |  l
 *   AddObjects       |  o
 *    Compile  (Run)  |  o
 *     Execute        |  p
 *    Reset  ---------+  |
 *  UnLoad---------------+
 * 
 * 
 */

namespace mol
{

    ///////////////////////////////////////////////////////////////////////
    // the JIT compiler outer implementation
    ///////////////////////////////////////////////////////////////////////

    [
        Guid("08452484-22AA-4429-B2D0-B5370712DD39"),
        ClassInterface(ClassInterfaceType.None ),
        ComSourceInterfaces(typeof(ICompilerMsg))
    ]
    public class JIT : MarshalByRefObject, ICompiler, IScriptCallback
    {
        public JIT()
        {
        }

        ///////////////////////////////////////////////////////////////////////

        public event CompilerErrorMsgDelegate ErrorMsg;
        public event CompilerSuccessMsgDelegate Success;

        ///////////////////////////////////////////////////////////////////////

        public void AddObject(string name, object o)
        {
            scriptingObjects.Add(name,o);
        }

        public void ClearObjects()
        {
            scriptingObjects.Clear();
        }

        public void AddSourceText(string src)
        {
            jit.AddSourceText(src);
        }

        public void AddSourceFile(string src)
        {
            jit.AddSourceFile(src);
        }

        public void ClearSources()
        {
            jit.ClearSources();
        }

        public void AddReference(string r)
        {
            jit.AddReference(r);
        }

        public void ClearReferences()
        {
            jit.ClearReferences();
        }


        public void AddDirectory(string d)
        {
            jit.AddDirectory(d);
        }

        public void ClearDirectories()
        {
            jit.ClearDirectories();
        }

        public string AssemblyName
        {
            get 
            {
                return jit.AssemblyName;
            }
            set 
            {
                jit.AssemblyName = value;   
            }
        }


        public string Options
        {
            get
            {
                return jit.Options;
            }
            set
            {
                jit.Options = value;
            }
        }

        public bool GenerateExecutable
        {
            get
            {
                return jit.GenerateExecutable;
            }
            set
            {
                jit.GenerateExecutable = value;
            }
        }

        public bool Optimize
        {
            get
            {
                return jit.Omptimize;
            }
            set
            {
                jit.Omptimize = value;
            }
        }

        public bool DebugInfo
        {
            get
            {
                return jit.DebugInfo;
            }
            set
            {
                jit.DebugInfo = value;
            }
        }

        public bool Win32Target
        {
            get
            {
                return jit.Win32Target;
            }
            set
            {
                jit.Win32Target = value;
            }
        }

        ///////////////////////////////////////////////////////////////////////

        public void Start()
        {
            if (executionDomain != null)
                this.Unload(true);

            // create new somewhat unique appdomain
            string tmp = System.Environment.TickCount.ToString();

            AppDomainSetup setup = new AppDomainSetup();
            setup.ShadowCopyFiles = "true";

            executionDomain = AppDomain.CreateDomain("mol.JIT.Domain." + tmp,null,setup);

            // create a script manager for this script in our new appdomain
            jit = (JITcompiler)executionDomain
                .CreateInstanceFromAndUnwrap(
                    typeof(JITcompiler).Assembly.Location,
                    typeof(JITcompiler).FullName
                  );
        }

        public void Compile()
        {
            if (executionDomain == null)
                this.Reset();

            if (this.jit.Success)
                this.Start();

            // go with new thread to do the compilation async
            t = new Thread(this.compile);

            // COM compat enforce
            t.SetApartmentState(ApartmentState.STA);
            t.Start();
        }

        public void Run()
        {
            if (this.jit == null)
                throw new Exception("load compiler before exec");


            //check if we have an successfull in memory build
            if ( this.jit.GenerateInMemory &&
                 this.jit.GenerateExecutable &&
                 this.jit.Success )
            {
                this.Exec();
                return;
            }

            //if we have a output file
            if ( this.jit.AssemblyName != null )
            {               
                // if source files avail check dates
                DateTime f_date = File.GetLastWriteTime(this.jit.AssemblyName);

                // start new compilation if any src file is newer
                if (jit.OutOfSync(f_date))
                {
                     CompileExec();
                     return;
                }

                // if we do not have a successful in-memory build, compile and execute
                if ((this.AssemblyName == null || this.AssemblyName.Equals("")) &&  !this.jit.Success)
                {
                    CompileExec();
                    return;
                }

                // if we get here, just execute our assembly
                this.Exec();
            }
        }

        public void Exec()
        {
            t = new Thread(this.execute);

            // COM compat enforce
            t.SetApartmentState(ApartmentState.STA);
            t.Start();
        }

        public void CompileExec()
        {
            t = new Thread(this.compileAndExecute);

            // COM compat enforce
            t.SetApartmentState(ApartmentState.STA);
            t.Start();
        }

        ///////////////////////////////////////////////////////////////////////

        public void Unload(bool clear)
        {
            if (executionDomain == null)
            {
                if (clear)
                {
                    this.Clear();
                }
                return;
            }

            // abort worker thread failsafe
            if (t!=null && !Thread.CurrentThread.Equals(t))
            {
                try
                {
                    t.Abort();
                }
                catch (ThreadAbortException e)
                {
                    System.Diagnostics.Trace.WriteLine(e.Message); 
                }
            }

            // Reset Datastructures
            foreach (KeyValuePair<string, object> kvp in scriptingObjects)
            {
                object o = executionDomain.GetData(kvp.Key);
                if (o != null)
                {
                    executionDomain.SetData(kvp.Key, null);
                    if (Marshal.IsComObject(kvp.Value))
                        Marshal.ReleaseComObject(kvp.Value);
                }
            }

            if (clear)
            {
                this.Clear();
            }

            // unload .NET domain
            try
            {
                AppDomain.Unload(executionDomain);
                executionDomain = null;
            }
            catch (AppDomainUnloadedException e)
            {
                System.Diagnostics.Trace.WriteLine(e.Message);
            }
        }

        ///////////////////////////////////////////////////////////////////////

        public void Reset()
        {
            this.Unload(false);
            this.Start();
        }

        ///////////////////////////////////////////////////////////////////////

        public void OnCompilerError(string errors)
        {
            if ( ErrorMsg != null )
                ErrorMsg(errors);
        }

        ///////////////////////////////////////////////////////////////////////
        // helper
        ///////////////////////////////////////////////////////////////////////

        private void Clear()
        {
            this.jit.AssemblyName = null;
            this.jit.GenerateExecutable = true;
            scriptingObjects.Clear();

            this.jit.ClearSources();
            this.jit.ClearReferences();
        }

        ///////////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////////
        // worker function for on the fly async compilation
        ///////////////////////////////////////////////////////////////////////

        private void compile()
        {
            try
            {
                doCompilation();
            }
            catch (AppDomainUnloadedException e)
            {
                System.Diagnostics.Trace.WriteLine(e.Message);
            }
            catch (ThreadAbortException tae)
            {
                System.Diagnostics.Trace.WriteLine(tae.Message);
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message,"JIT.compile");
            }
        }

        ///////////////////////////////////////////////////////////////////////
        // worker function for on the fly async compilation
        ///////////////////////////////////////////////////////////////////////

        private void compileAndExecute()
        {
            try
            {
                doCompilation();

                execute();
            }
            catch (AppDomainUnloadedException e)
            {
                System.Diagnostics.Trace.WriteLine(e.Message);
            }
            catch (ThreadAbortException tae)
            {
                System.Diagnostics.Trace.WriteLine(tae.Message);
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message, "JIT.compileAndExecute");
            }
        }

        ///////////////////////////////////////////////////////////////////////
        // worker function for on the fly async execution
        ///////////////////////////////////////////////////////////////////////

        private void execute()
        {
            try
            {
                if ( executionDomain != null && jit != null)
                {
                    // inject COM references into that appdomain
                    foreach (KeyValuePair<string, object> kvp in scriptingObjects)
                    {
                        object o = executionDomain.GetData(kvp.Key);
                        if (o != null)
                        {
                            if (Marshal.IsComObject(o))
                                Marshal.ReleaseComObject(o);
                            executionDomain.SetData(kvp.Key, null);
                        }
                        executionDomain.SetData(kvp.Key, kvp.Value);
                    }
                    //executionDomain.CreateInstanceAndUnwrap("moe", "mol.moe");
                    // let it run, baby, run
                    jit.execute();
                }
            }
            catch (AppDomainUnloadedException e)
            {
                System.Diagnostics.Trace.WriteLine(e.Message);
            }
            catch (ThreadAbortException tae)
            {
                System.Diagnostics.Trace.WriteLine(tae.Message);
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message, "JIT.execute");
            }
        }

        ///////////////////////////////////////////////////////////////////////
        // helper for actual compilation
        ///////////////////////////////////////////////////////////////////////

        private void doCompilation()
        {
            //compile
            jit.compile(this);

            // raise event
            if (Success != null)
                Success();
        }

        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////

        // worker thread
        private Thread t = null;

        // COM objects for scripting
        private Dictionary<string, object> scriptingObjects = new Dictionary<string, object>();

        // compiler impl
        private JITcompiler jit = null;

        // execution domain for script ececution
        private AppDomain executionDomain = null;

    }
}
