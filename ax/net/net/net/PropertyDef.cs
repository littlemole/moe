using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace org.oha7.dotnet
{
    public class PropertyDef
    {
        public String name;
        public Type type;
        public Object[] attributes;

        public PropertyDef(String n, Type t, Object[] attrs)
        {
            name = n;
            type = t;
            attributes = attrs;
        }

        public static PropertyDef instance(String name, Type type, Object[] attrs)
        {
            return new PropertyDef(name, type, attrs);
        }
    }
}
