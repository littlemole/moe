using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Reflection;

namespace org.oha7.dotnet
{
    public class MethodHandle
    {
        public String name;
        public Type type;
        public Object[] args;

        public MethodHandle(String n, Type t, Object[] a)
        {
            name = n;
            args = a;
            type = t;
        }

        public static MethodHandle instance(String n, Type t, object[] a)
        {
            return new MethodHandle(n, t, RefWrapper.unwrap(a));
        }

        public static Object invoke(object target, String method, object[] args)
        {
            object[] a = null;

            
            if ( args != null ) {
                a = new object[args.Length];
                if (args.Length > 0)
                {
                    //a[0] = args[0];
                    for (int i = 0; i < args.Length; i++)
                    {
                        if (args[i] is RefWrapper)
                        {
                            a[i] = args[i];
                        }
                        else
                        {
                            a[i] = RefWrapper.wrap(args[i]);
                        }
                    }
                }
            }
            
            Object o = target.GetType().InvokeMember(
                            method,
                            BindingFlags.Instance | BindingFlags.InvokeMethod | BindingFlags.Public,
                            null,
                            target,
                            a
                   );
            return RefWrapper.unwrap(o);
        }
    }
}
