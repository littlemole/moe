﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace org.oha7.dotnet
{
    class RefWrapper : MarshalByRefObject
    {
        private Object reference = null;

        public RefWrapper()
        {
        }

        public RefWrapper(Object o)
        {
            reference = o;
        }

        public Object unwrap()
        {
            return reference;
        }

        public static Object wrap(Object o)
        {
            if (o == null)
            {
                return null;
            }

            if (o is RefWrapper)
            {
                return o;
            }

            if (o.GetType().IsPrimitive)
            {
                return o;
            }

            if (o is System.Byte|| o is System.Char || o is System.Int16 || o is System.Int32 || o is System.Int64 || o is System.IntPtr || o is System.String || o is System.Boolean || o is System.Double)
            {
                return o;
            }

            return new RefWrapper(o);            
        }

        public static Object[] wrap(Object[] args)
        {
            if (args == null || args.Length == 0)
                return args;

            int len = args.Length;
            for (int i = 0; i < len; i++)
            {
                args[i] = RefWrapper.wrap(args[i]);
            }
            return args;
        }

        public static Object unwrap( Object o)
        {
            if (o is RefWrapper)
            {
                o = ((RefWrapper)o).unwrap();
            }
            return o;
        }

        public static Object[] unwrap(Object[] args)
        {
            if (args == null || args.Length == 0)
                return args;

            int len = args.Length;
            for (int i = 0; i < len; i++)
            {
                args[i] = RefWrapper.unwrap(args[i]);
            }
            return args;
        }

    }
}
