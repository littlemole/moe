using System;
using System.Collections;
using System.Runtime.InteropServices;
using System.Reflection;

namespace mol
{
    ///////////////////////////////////////////////////////////////////////
    // External obj helper
    ///////////////////////////////////////////////////////////////////////

    [ComVisible(false)]
    public class External<T> 
    {
        public static T obj(string name)
        {
            return (T)AppDomain.CurrentDomain.GetData(name);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // internal error callback interface
    ///////////////////////////////////////////////////////////////////////

    [ComVisible(false)]
    public interface IScriptCallback
    {
        void OnCompilerError(string errors);
    }

    ///////////////////////////////////////////////////////////////////////
    // ICompiler COM interface
    ///////////////////////////////////////////////////////////////////////

    [
        Guid("B237A73F-7E03-402b-A4B0-5ABE252EA4F8"),
        InterfaceType(ComInterfaceType.InterfaceIsDual)
    ]
    public interface ICompiler
    {
        [DispId(1)] // add scripting object
        void AddObject(string name, object o);

        [DispId(2)] // clear list of scripting objects
        void ClearObjects();

        [DispId(3)] // add source text
        void AddSourceText(string src);

        [DispId(4)] // add source file path
        void AddSourceFile(string src);

        [DispId(5)] // clear list of source texts and files
        void ClearSources();

        [DispId(6)] // add a .dll reference to build
        void AddReference(string r);

        [DispId(7)] // clear list of references
        void ClearReferences();

        [DispId(8)] // add a include directory to searchpath
        void AddDirectory(string d);

        [DispId(9)] // clear list of include directories
        void ClearDirectories();

        [DispId(10)] // set output name (usually .exe)
                    // if no name given, a in memory build is done
        string AssemblyName
        {
            get;
            set;
        }

        [DispId(11)] // generate .exe (true,default) or .dll (false)
        bool GenerateExecutable
        {
            get;
            set;
        }

        [DispId(12)] // flag .exe as win32 app, no attached console
        bool Win32Target
        {
            get;
            set;
        }

        [DispId(13)] // set optimize flag
        bool Optimize 
        {
            get;
            set;
        }

        [DispId(14)] // include debug info
        bool DebugInfo
        {
            get;
            set;
        }

        [DispId(15)] // further options to pass on commandline
        string Options
        {
            get;
            set;
        }

        [DispId(16)] // initialize compiler. if not reseted will do full reset first
        void Start();

        [DispId(17)] // async compile with given sources and parameters
        void Compile();

        [DispId(18)] // async execute current build
        void Exec();

        [DispId(19)] // async compile and execute build
        void CompileExec();

        [DispId(20)] // run existing, rebuild if newer
        void Run();

        [DispId(21)] // unload execution domain. clear:true will do a full
                     // reset, clear:false will keep parameters
        void Unload(bool clear);

        [DispId(22)] // calls Unload(false), then Start().
        void Reset();

    }

    ///////////////////////////////////////////////////////////////////////
    // Compiler source (event) interface
    ///////////////////////////////////////////////////////////////////////

    [
        Guid("AAD393B7-F8E1-4e25-88FA-317E0E4759EB"),
        InterfaceType(ComInterfaceType.InterfaceIsIDispatch)
    ]

    public interface ICompilerMsg
    {
        [DispId(1)]
        void ErrorMsg(string errors);
        [DispId(2)]
        void Success();
    }

    ///////////////////////////////////////////////////////////////////////
    // Compiler source (event) dual interface
    ///////////////////////////////////////////////////////////////////////

    [
        Guid("8A5A643A-EDCC-4501-8AED-3A38AA9AD19C"),
        InterfaceType(ComInterfaceType.InterfaceIsDual)
    ]

    public interface ICompilerDualMsg
    {
        [DispId(1)]
        void ErrorMsg(string errors);
        [DispId(2)]
        void Success();
    }

    ///////////////////////////////////////////////////////////////////////

    public delegate void CompilerErrorMsgDelegate(string errors);

    public delegate void CompilerSuccessMsgDelegate();

    ///////////////////////////////////////////////////////////////////////
}
