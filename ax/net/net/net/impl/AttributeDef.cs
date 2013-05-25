using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace org.oha7.dotnet
{
    public class AttributeDef
    {
        public Type type;
        public Object[] args;
        public AttributeDef(Type t, Object[] a)
        {
            type = t;
            args = a;
        }

        public static AttributeDef instance(Type type, Object[] args)
        {
            return new AttributeDef(type, RefWrapper.unwrap(args));
        }

    }
}
