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
            return target.GetType().InvokeMember(
                            method,
                            BindingFlags.Instance | BindingFlags.InvokeMethod | BindingFlags.Public,
                            null,
                            target,
                            args
                   );

        }
    }
}
