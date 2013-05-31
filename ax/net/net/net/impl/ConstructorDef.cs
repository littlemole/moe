using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace org.oha7.dotnet
{
    public class ConstructorDef
    {
        public String name;
        public Type type;
        public Object[] args;

        public ConstructorDef(Type t, String n, Object[] a)
        {
            name = n;
            type = t;
            args = a;
        }

        public static ConstructorDef instance(String name, Type type, Object[] args)
        {
            return new ConstructorDef(type, name,args);
        }


        public static Object invoke(object target, String method, object[] args)
        {
            object[] a = RefWrapper.wrap(args);

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
