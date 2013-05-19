﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Reflection;

namespace org.oha7.dotnet
{
    /**
     * Native-Net Bridge
     * 
     * */
    [
        Guid("F751B363-9E23-4DA7-B18C-B835AE59DF5B"),
        ClassInterface(ClassInterfaceType.AutoDual)
    ]
    public class Net :  MarshalByRefObject
    {
        // IDispatch Flags
        private static  int DISPATCH_METHOD = 1;
        private static  int DISPATCH_PROPERTYGET = 2;
        private static  int DISPATCH_PROPERTYPUT = 4;
        private static  int DISPATCH_PROPERTYPUTREF = 8;

        // caches
        private static Dictionary<String, Object> netTypeCache = new Dictionary<string, object>();
        private static Dictionary<String, Object> assemblyCache = new Dictionary<string, object>();

         
        /**
         * Load a Net Type
         * 
         * t : refwrapper for a .NET Assembly 
         * name : name of type
         * */

        [DispId(1)]
        public Object LoadClass(Object t, String name)
        {
            // try type cache first
            if (netTypeCache.ContainsKey(name))
            {
                return RefWrapper.wrap(netTypeCache[name]);
            }

            // try to find with system loader
            Type type = Type.GetType(name);
            if (type != null)
            {
                netTypeCache.Add(name, type);
                return RefWrapper.wrap(type);
            }

            // try assemblies in assembly cache
            foreach( Object ca in assemblyCache.Values )
            {
                Assembly assembly = (Assembly)ca;
                type = assembly.GetType(name);
                if (type != null)
                {
                    netTypeCache.Add(name, type);
                    return RefWrapper.wrap(type);
                }
            }

            // get assembly reference
            t = RefWrapper.unwrap(t);
            if (t == null)
                return null;

            Assembly a = (Assembly)t;
            type = a.GetType(name);
            if (type != null)
            {
                netTypeCache.Add(name, type);
                return RefWrapper.wrap(type);
            }
            return null;
        }

        /**
         * create a .NET object
         * 
         * t : refwrapper to .NET type
         * args : array with params for constructor call
         * 
         * */
        [DispId(2)]
        public Object CreateObject(Object t,Object[] args)
        {
            t = RefWrapper.unwrap(t);

            Type type = (Type)t;

            if ( type.Equals(typeof(System.String)) && 
                 args.Length == 1 && 
                 args[0] is System.String)
            {
                // note: force RefWrapper using new even for Strings
                return new RefWrapper(args[0]);
            }
            
            args = unwrapArgs(args);

            ConstructorInfo ci = resolveConstructor(type,args);// type.GetConstructor(getArgTypes(args));
            if (ci != null)
            {
                return RefWrapper.wrap(ci.Invoke(args));
            }
            return null;
        }

        /**
         * Invoke a method on a .NET type or object
         * 
         * t: .NET type  - may be null if that is set
         * that: this pointer refwrapped of .NET object. if null a static call is made
         * args: parameters for method call
         * flags: dispatch flag (ie get/set)
         * */

        [DispId(3)]
        public Object InvokeMethod(Object t, Object that, String methodName, Object[] args, int flags)
        {            

            if (t == null && that == null)
                return null;

            if (t == null)
            {
                that = RefWrapper.unwrap(that);
                t = that.GetType();
            }
            else
            {
                t = RefWrapper.unwrap(t);
            }

            if (flags == DISPATCH_PROPERTYGET)
                return RefWrapper.wrap(invokeGetProperty(t, that, methodName, unwrapArgs(args)));

            if (flags == DISPATCH_PROPERTYPUT)
                return RefWrapper.wrap(invokePutProperty(t, that, methodName, unwrapArgs(args)));


            return RefWrapper.wrap(invoke(t, that, methodName, unwrapArgs(args)));
        }

        /**
         * Load a .NET assembly
         * 
         * name: assembly to load
         * */
        [DispId(4)]
        public Object LoadAssembly(String name)
        {
            if ( assemblyCache.ContainsKey(name) )
            {
                return RefWrapper.wrap(assemblyCache[name]);
            }

            Assembly a = Assembly.LoadWithPartialName(name);      
      
            if ( a == null )
                return null;

            assemblyCache.Add(name, a);
            return RefWrapper.wrap(a);
        }

        /**
         * attach .NET event to dispatch handler
         * 
         * target : source obj of event (ie a form)
         * name : name of event type
         * ptr : native Dispatch ptr to script handler
         * */
        [DispId(5)]
        public void Event(Object target, String name, Object ptr)
        {
            target = RefWrapper.unwrap(target);
            Type t = target.GetType();

            EventInfo ev = t.GetEvent(name);
            Type delegateType = ev.EventHandlerType;

            MethodInfo miHandler = typeof(EventWrapper).GetMethod("eventMethod", 
                BindingFlags.NonPublic | BindingFlags.Public| BindingFlags.Instance );

            EventWrapper wrapper = new EventWrapper(ptr);
            Delegate d = Delegate.CreateDelegate(delegateType, wrapper, miHandler);

            MethodInfo addHandler = ev.GetAddMethod();
            addHandler.Invoke(target, new Object[]{ d } );
        }

        [DispId(6)]
        public Object Prototype(String name, Object[] properties, Object[] classes)
        {
            if (properties.Length != classes.Length)
                return null;

            int len = properties.Length;

            string[] names = new string[len];
            for (int i = 0; i < len; i++)
            {
                names[i] = (string)RefWrapper.unwrap(properties[i]);
            }

            Type[] types = new Type[len];
            for (int i = 0; i < len; i++)
            {
                Object o = RefWrapper.unwrap(classes[i]);
                if ( o is Type )
                {
                    types[i] = (Type)o;
                }
                else if (o is System.Int32)
                {
                    types[i] = typeof(System.Int32);
                }
                else if (o is System.String)
                {
                    types[i] = typeof(System.String);
                }
            }

            object result = org.oha7.dotnet.Prototype.createType(name, names, types);
            
            return RefWrapper.wrap(result);
        }


        [DispId(7)]
        public Object MakeGeneric(Object t, Object[] args)
        {
            Type type = (Type)RefWrapper.unwrap(t);
            Type[] types = new Type[args.Length];
            for (int i = 0; i < args.Length; i++)
            {
                types[i] = (Type)RefWrapper.unwrap(args[i]);
            }

            Type result = type.MakeGenericType(types);
            return result;
        }

        private T[] getClassDefs<T>(Object[] array)
        {
            if (array == null)
                return null;

            T[] a = new T[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                a[i] = (T)RefWrapper.unwrap(array[i]);
            }
            return a;
        }

        [DispId(8)]
        public Object DefineClass(String typeName, Object baseType, Object[] interfaces, Object[] attrs, Object[] properties, Object[] handles)
        {
            Type[] iTypes = getClassDefs<Type>(interfaces);
            AttributeDef[] atts = getClassDefs<AttributeDef>(attrs);
            PropertyDef[] props = getClassDefs<PropertyDef>(properties);
            MethodHandle[] meths = getClassDefs<MethodHandle>(handles);

            Object result = ClassFactory.makeClass(
                typeName,
                (Type)RefWrapper.unwrap(baseType),
                iTypes,
                atts,props,meths
                );

            return RefWrapper.wrap(result);
        }
        
        /*
        private object[] unwrap(object[] args)
        {
            object[] result = new object[args.Length];
            for (int i = 0; i < args.Length; i++)
            {
                result[i] = RefWrapper.unwrap(args[i]);
            }
            return result;
        }
        */
        public static void cacheType(String name, Type type)
        {
            netTypeCache.Add(name, type);
        }

        // invoke helper
        private Object invoke(Object clazz, Object that, String methodName, Object[] args)
        {
            Type type = (Type)clazz;

            MethodInfo mi = resolveMethod(type, methodName, args);
            if (mi != null)
            {
                if (!mi.ReturnType.Equals(typeof(void)))
                {
                    return mi.Invoke(that, args);
                }
                else
                {
                    mi.Invoke(that, args);
                    return null;
                }
            }
            throw new MissingMemberException();
//            return null;
        }

        // get property helper
        private Object invokeGetProperty(Object clazz, Object that, String propertyName, Object[] args)
        {
            Type type = (Type)clazz;
            PropertyInfo pi = type.GetProperty(propertyName);
            if (pi != null)
            {
                return pi.GetValue(that,null);
            }

            FieldInfo field = type.GetField(propertyName);
            if (field != null)
            {
                return field.GetValue(that);
            }

            EventInfo info = type.GetEvent(propertyName);
            if (info != null)
            {
                return info;
            }

            if (type.IsEnum)
            {
                String[] names = type.GetEnumNames();
                for (int i = 0; i < names.Length; i++)
                {
                    if (names[i].Equals(propertyName))
                    {
                        Array a = type.GetEnumValues();
                        return a.GetValue(i);
                    }
                }
            }

            String methodName = "get" + propertyName;
            return invoke(clazz, that, methodName, args);
        }

        // property put helper
        private Object invokePutProperty(Object clazz, Object that, String propertyName, Object[] args)
        {
            Type type = (Type)clazz;
            PropertyInfo pi = type.GetProperty(propertyName);
            if (pi != null)
            {
                pi.SetValue(that, args[0],null);
                return null;
            }

            FieldInfo field = type.GetField(propertyName);
            if (field != null)
            {
                field.SetValue(that,args[0]);
                return null;
            }

            String methodName = "set" + propertyName;
            return invoke(clazz, that, methodName, args);
        }

        // get type array for obj array
        private Type[] getArgTypes(Object[] args)
        {
            if (args == null || args.Length == 0)
                return new Type[] { };

            int len = args.Length;
            Type[] argTypes = new Type[len];

            for (int i = 0; i < len; i++)
            {
                if (args[i] == null)
                {
                    argTypes[i] = null;
                }
                else
                {
                    argTypes[i] = args[i].GetType();
                }
            }
            return argTypes;
        }

        // unwrap arguments
        private Object[] unwrapArgs(Object[] args)
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

        // resolve method
        private MethodInfo resolveMethod(Type type, String methodName, Object[] args)
        {
            Type[] types = getArgTypes(args);
            try
            {
                MethodInfo mi = type.GetMethod(methodName, types);
                if (mi != null)
                {
                    return mi;
                }
            }
            catch(Exception)
            {}

            MethodInfo[] methods = type.GetMethods();
            for (int i = 0; i < methods.Length; i++)
            {
                MethodInfo m = methods[i];
                if (m.Name.Equals(methodName) || m.Name.Equals("get_" + methodName))
                {
                    ParameterInfo[] pi = m.GetParameters();
                    if (pi.Length == types.Length)
                    {
                        bool match = true;
                        for (int j = 0; j < types.Length; j++)
                        {
                            if (types[j] == null)
                                continue;

                            if (!pi[j].ParameterType.IsAssignableFrom(types[j]))
                            {                                
                                match = false;
                                break;
                            }
                        }
                        if(match)
                            return m;
                    }
                }
            }
            return null;
        }
    
        // resolve method
        private ConstructorInfo resolveConstructor(Type type, Object[] args)
        {
            Type[] types = getArgTypes(args);
            ConstructorInfo ci = type.GetConstructor(types);
            if (ci != null)
            {
                return ci;
            }

            ConstructorInfo[] constructors = type.GetConstructors();
            for (int i = 0; i < constructors.Length; i++)
            {
                ConstructorInfo c = constructors[i];
                ParameterInfo[] pi = c.GetParameters();
                if (pi.Length == types.Length)
                {
                    bool match = true;
                    for (int j = 0; j < types.Length; j++)
                    {
                        if (!pi[j].ParameterType.IsAssignableFrom(types[j]))
                        {
                            match = false;
                            break;
                        }
                    }
                    if(match)
                        return c;
                }
            }
            return null;
        }
    }
}
