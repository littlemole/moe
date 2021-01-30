using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.CSharp;
using System.CodeDom.Compiler;
using System.Reflection;
using System.Reflection.Emit;

namespace org.oha7.dotnet
{
    class Compiler
    {
        static void Main(string[] args)
        {
            var csc = new CSharpCodeProvider(new Dictionary<string, string>() { });// "CompilerVersion", "v3.5" } });
            var parameters = new CompilerParameters(new[] { "mscorlib.dll", "System.Core.dll" }, "foo.exe", true);
            parameters.GenerateExecutable = true;
            parameters.GenerateInMemory = true;
            CompilerResults results = csc.CompileAssemblyFromSource(parameters,
            @"using System.Linq;
            class Program {
              public static void Main(string[] args) {
                var q = from i in Enumerable.Range(1,100)
                          where i % 2 == 0
                          select i;
              }
            }");
            results.Errors.Cast<CompilerError>().ToList().ForEach(error => Console.WriteLine(error.ErrorText));

            Assembly a = results.CompiledAssembly;
            Module[] modules = a.GetModules();
            foreach( Module m in modules)
            {
                Type[] types = m.GetTypes();
                foreach(Type type in types)
                {
                    MethodInfo[] mis = type.GetMethods();
                    foreach(MethodInfo mi in mis )
                    {
                        if(mi.Name == "Main")
                        {
                            mi.Invoke(null, new object[] { });
                            return;
                        }
                    }
                }
            }
        }
    }
}
