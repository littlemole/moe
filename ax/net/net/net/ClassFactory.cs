using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Reflection;
using System.Reflection.Emit;
using System.Threading;

namespace org.oha7.dotnet
{
    public class ClassFactory
    {
        private static MethodInfo DelegateCombine = typeof(Delegate).GetMethod("Combine", new Type[] { typeof(Delegate), typeof(Delegate) });
        private static MethodInfo DelegateRemove = typeof(Delegate).GetMethod("Remove", new Type[] { typeof(Delegate), typeof(Delegate) });
        private static MethodInfo InvokeDelegate = typeof(PropertyChangedEventHandler).GetMethod("Invoke");
        private static MethodInfo CallbackDelegate = typeof(MethodHandle).GetMethod("invoke", BindingFlags.Static | BindingFlags.Public);
        private static ConstructorInfo CreateEventArgs = typeof(PropertyChangedEventArgs).GetConstructor(new Type[] { typeof(String) });
        private static MethodAttributes getSetAttr = MethodAttributes.Public | MethodAttributes.SpecialName | MethodAttributes.HideBySig;

        private static Dictionary<string, Type> typeCache = new Dictionary<string, Type>();

        private static readonly Hashtable opCodeTypeMapper = new Hashtable();

        private static AssemblyBuilder asmBuilder = null;

        static ClassFactory()
        {
            opCodeTypeMapper.Add(typeof(System.Boolean), OpCodes.Ldind_I1);
            opCodeTypeMapper.Add(typeof(System.Int16), OpCodes.Ldind_I2);
            opCodeTypeMapper.Add(typeof(System.Int32), OpCodes.Ldind_I4);
            opCodeTypeMapper.Add(typeof(System.Int64), OpCodes.Ldind_I8);
            opCodeTypeMapper.Add(typeof(System.Double), OpCodes.Ldind_R8);
            opCodeTypeMapper.Add(typeof(System.Single), OpCodes.Ldind_R4);
            opCodeTypeMapper.Add(typeof(System.UInt16), OpCodes.Ldind_U2);
            opCodeTypeMapper.Add(typeof(System.UInt32), OpCodes.Ldind_U4);
            opCodeTypeMapper.Add(typeof(System.IntPtr), OpCodes.Ldind_U4);
        }

        private static ModuleBuilder getBuilder(String typeName)
        {
            asmBuilder = null;
            ModuleBuilder modBuilder = null;

            AssemblyName assemblyName = new AssemblyName();
            assemblyName.Name = typeName;

            AppDomain thisDomain = Thread.GetDomain();
            asmBuilder = thisDomain.DefineDynamicAssembly(
                            assemblyName,
                            AssemblyBuilderAccess.RunAndSave, "D:\\"
                           );

            modBuilder = asmBuilder.DefineDynamicModule(
                         asmBuilder.GetName().Name, "test.dll"
                      );

            return modBuilder;
        }

        private static TypeBuilder getTypeBuilder(String typeName, Type baseClass)
        {
            ModuleBuilder modBuilder = getBuilder(typeName);

            TypeBuilder typeBuilder = modBuilder.DefineType(typeName,
                TypeAttributes.Public |
                TypeAttributes.Class |
                TypeAttributes.AutoClass |
                TypeAttributes.AnsiClass |
                TypeAttributes.BeforeFieldInit |
                TypeAttributes.AutoLayout,
                baseClass,
                new Type[] { });

            return typeBuilder;
        }

        private static MethodBuilder make_AddPropertyChanged(TypeBuilder typeBuilder, FieldBuilder eventBack)
        {
            MethodBuilder AddPropertyChanged = typeBuilder.DefineMethod(
                            "add_PropertyChanged",
                            MethodAttributes.Public | MethodAttributes.Virtual | MethodAttributes.SpecialName | MethodAttributes.Final | MethodAttributes.HideBySig | MethodAttributes.NewSlot,
                            typeof(void), new Type[] { typeof(PropertyChangedEventHandler) });


            ILGenerator addPropIL = AddPropertyChanged.GetILGenerator();
            addPropIL.Emit(OpCodes.Ldarg_0);
            addPropIL.Emit(OpCodes.Ldarg_0);
            addPropIL.Emit(OpCodes.Ldfld, eventBack);
            addPropIL.Emit(OpCodes.Ldarg_1);
            addPropIL.Emit(OpCodes.Call, DelegateCombine);
            addPropIL.Emit(OpCodes.Castclass, typeof(PropertyChangedEventHandler));
            addPropIL.Emit(OpCodes.Stfld, eventBack);
            addPropIL.Emit(OpCodes.Ret);

            return AddPropertyChanged;
        }

        private static MethodBuilder make_RemovePropertyChanged(TypeBuilder typeBuilder, FieldBuilder eventBack)
        {
            MethodBuilder RemovePropertyChanged = typeBuilder.DefineMethod(
                            "remove_PropertyChanged", MethodAttributes.Public | MethodAttributes.Virtual | MethodAttributes.SpecialName | MethodAttributes.Final | MethodAttributes.HideBySig | MethodAttributes.NewSlot,
                            typeof(void), new Type[] { typeof(PropertyChangedEventHandler) });

            ILGenerator delPropIL = RemovePropertyChanged.GetILGenerator();
            delPropIL.Emit(OpCodes.Ldarg_0);
            delPropIL.Emit(OpCodes.Ldarg_0);
            delPropIL.Emit(OpCodes.Ldfld, eventBack);
            delPropIL.Emit(OpCodes.Ldarg_1);
            delPropIL.Emit(OpCodes.Call, DelegateRemove);
            delPropIL.Emit(OpCodes.Castclass, typeof(PropertyChangedEventHandler));
            delPropIL.Emit(OpCodes.Stfld, eventBack);
            delPropIL.Emit(OpCodes.Ret);

            return RemovePropertyChanged;
        }

        private static MethodBuilder make_RaisePropertyChanged(TypeBuilder typeBuilder, FieldBuilder eventBack)
        {
            MethodBuilder RaisePropertyChanged = typeBuilder.DefineMethod(
                "OnPropertyChanged", MethodAttributes.Public,
                typeof(void), new Type[] { typeof(String) });

            ILGenerator raisePropIL = RaisePropertyChanged.GetILGenerator();
            System.Reflection.Emit.Label lblDelegateOk = raisePropIL.DefineLabel();
            raisePropIL.DeclareLocal(typeof(PropertyChangedEventHandler));
            raisePropIL.Emit(OpCodes.Nop);
            raisePropIL.Emit(OpCodes.Ldarg_0);
            raisePropIL.Emit(OpCodes.Ldfld, eventBack);
            raisePropIL.Emit(OpCodes.Stloc_0);
            raisePropIL.Emit(OpCodes.Ldloc_0);
            raisePropIL.Emit(OpCodes.Ldnull);
            raisePropIL.Emit(OpCodes.Ceq);
            raisePropIL.Emit(OpCodes.Brtrue, lblDelegateOk);
            raisePropIL.Emit(OpCodes.Ldloc_0);
            raisePropIL.Emit(OpCodes.Ldarg_0);
            raisePropIL.Emit(OpCodes.Ldarg_1);
            raisePropIL.Emit(OpCodes.Newobj, CreateEventArgs);
            raisePropIL.Emit(OpCodes.Callvirt, InvokeDelegate);
            raisePropIL.MarkLabel(lblDelegateOk);
            raisePropIL.Emit(OpCodes.Ret);

            return RaisePropertyChanged;
        }

        private static FieldBuilder make_field(TypeBuilder typeBuilder, String name, Type type)
        {
            FieldBuilder field = typeBuilder.DefineField(name, type, FieldAttributes.Private);
            return field;
        }

        private static MethodBuilder getAccessor(TypeBuilder typeBuilder, String name, Type type, FieldBuilder value)
        {
            MethodBuilder accessor = typeBuilder.DefineMethod(
                        "get_" + name,
                        getSetAttr,
                        type,
                        Type.EmptyTypes);

            ILGenerator valueGetIL = accessor.GetILGenerator();
            valueGetIL.Emit(OpCodes.Ldarg_0);
            valueGetIL.Emit(OpCodes.Ldfld, value);
            valueGetIL.Emit(OpCodes.Ret);

            return accessor;
        }

        private static MethodBuilder getSetter(TypeBuilder typeBuilder, String name, Type type, FieldBuilder value, MethodBuilder raisePropertyChanged)
        {
            MethodBuilder setter = typeBuilder.DefineMethod(
                               "set_" + name,
                               getSetAttr,
                               null,
                               new Type[] { type });

            ILGenerator valueSetIL = setter.GetILGenerator();
            valueSetIL.Emit(OpCodes.Ldarg_0);
            valueSetIL.Emit(OpCodes.Ldarg_1);
            valueSetIL.Emit(OpCodes.Stfld, value);

            valueSetIL.Emit(OpCodes.Ldarg_0);
            valueSetIL.Emit(OpCodes.Ldstr, name);
            valueSetIL.Emit(OpCodes.Call, raisePropertyChanged);
            valueSetIL.Emit(OpCodes.Ret);

            return setter;
        }

        private static void make_property(TypeBuilder typeBuilder, PropertyDef property, MethodBuilder raisePropertyChanged)
        {
            FieldBuilder fieldBuilder = make_field(typeBuilder, /*"_" + */ property.name, property.type);

            PropertyBuilder propertyBuilder = typeBuilder.DefineProperty(
                property.name,
                System.Reflection.PropertyAttributes.HasDefault,
                property.type,
                null);

            MethodBuilder getter = getAccessor(typeBuilder, property.name, property.type, fieldBuilder);
            MethodBuilder setter = getSetter(typeBuilder, property.name, property.type, fieldBuilder, raisePropertyChanged);

            propertyBuilder.SetGetMethod(getter);
            propertyBuilder.SetSetMethod(setter);

            if(property.attributes!=null)
            foreach (AttributeDef attr in property.attributes)
            {
                Type[] ctorParams = typesFromArgs(attr.args);
                ConstructorInfo classCtorInfo = attr.type.GetConstructor(ctorParams);

                CustomAttributeBuilder myCABuilder = new CustomAttributeBuilder(
                                    classCtorInfo,
                                    attr.args);
                propertyBuilder.SetCustomAttribute(myCABuilder);
            }
        }

        private static Type[] typesFromArgs(Object[] args)
        {
            if (args == null)
                return null;

            Type[] result = new Type[args.Length];
            for (int i = 0; i < args.Length; i++)
            {
                if (args[i] is Type)
                {
                    result[i] = (Type)args[i];
                }
                else
                {
                    result[i] = args[i].GetType();
                }
            }
            return result;
        }

        public static Type makeClass(String typeName, Type baseType, Type[] interfaces, AttributeDef[] attrs, PropertyDef[] properties, MethodHandle[] handles)
        {
            if (typeCache.ContainsKey(typeName))
            {
                return typeCache[typeName];
            }

            TypeBuilder typeBuilder = getTypeBuilder(typeName, baseType);

            typeBuilder.AddInterfaceImplementation(typeof(INotifyPropertyChanged));
            if(interfaces != null)
            foreach (Type i in interfaces)
            {
                if (!i.Equals(typeof(INotifyPropertyChanged)))
                {
                    typeBuilder.AddInterfaceImplementation(i);
                }
            }

            if (attrs != null)
            foreach (AttributeDef attr in attrs)
            {
                Type[] ctorParams = typesFromArgs(attr.args);
                ConstructorInfo classCtorInfo = attr.type.GetConstructor(ctorParams);

                CustomAttributeBuilder myCABuilder = new CustomAttributeBuilder(
                                    classCtorInfo,
                                    attr.args);

                typeBuilder.SetCustomAttribute(myCABuilder);
            }

            FieldBuilder eventBack = make_field(typeBuilder, "PropertyChanged", typeof(PropertyChangedEventHandler));

            FieldBuilder handlerField = typeBuilder.DefineField(
                "ScriptHandler", typeof(Object), FieldAttributes.Public | FieldAttributes.Static);

            MethodBuilder addPropertyChanged = make_AddPropertyChanged(typeBuilder, eventBack);
            MethodBuilder removePropertyChanged = make_RemovePropertyChanged(typeBuilder, eventBack);
            MethodBuilder raisePropertyChanged = make_RaisePropertyChanged(typeBuilder, eventBack);

            EventBuilder pcevent = typeBuilder.DefineEvent("PropertyChanged", EventAttributes.None, typeof(PropertyChangedEventHandler));
            pcevent.SetRaiseMethod(raisePropertyChanged);
            pcevent.SetAddOnMethod(addPropertyChanged);
            pcevent.SetRemoveOnMethod(removePropertyChanged);

            if (properties != null)
            {
                int nProperties = properties.Length;
                for (int i = 0; i < nProperties; i++)
                {
                    make_property(typeBuilder, properties[i], raisePropertyChanged);
                }
            }

            if ( handles != null )
            for (int i = 0; i < handles.Length; i++)
            {
                make_method(typeBuilder, handles[i], handlerField);
            }

            Type type = typeBuilder.CreateType();
            typeCache.Add(typeName, type);
            Net.cacheType(typeName, type);

            asmBuilder.Save("test.dll");
            return type;

        }

        private static MethodBuilder make_method(TypeBuilder typeBuilder, MethodHandle methodHandle, FieldBuilder handlerField)
        {
            Type[] types = typesFromArgs(methodHandle.args);

            MethodBuilder methodBuilder = typeBuilder.DefineMethod(
                                            methodHandle.name,
                                            MethodAttributes.Public | MethodAttributes.Virtual,
                                            methodHandle.type != null
                                                    ? methodHandle.type
                                                    : typeof(void),
                                            types
                                        );

            ILGenerator methodIL = methodBuilder.GetILGenerator();


            methodIL.DeclareLocal(typeof(System.Object[]));

            // Emit a declaration of a local variable if there is a return
            // type defined
            if (methodHandle.type != null && !methodHandle.type.Equals(typeof(void)))
            {
                methodIL.DeclareLocal(methodHandle.type);
                if (methodHandle.type.IsValueType && !methodHandle.type.IsPrimitive)
                {
                    methodIL.DeclareLocal(methodHandle.type);
                }
            }

            // declare a lable for returning from the method
            Label returnLabel = methodIL.DefineLabel();

            // load "this"
            //methodIL.Emit(OpCodes.Ldarg_0);
            methodIL.Emit(OpCodes.Ldnull);
            // load the handler
            methodIL.Emit(OpCodes.Ldfld, handlerField);
            // load handler method name
            methodIL.Emit(OpCodes.Ldstr, methodHandle.name);

            int nArgs = methodHandle.args.Length;
            // prepare array of args. first load number of args
            methodIL.Emit(OpCodes.Ldc_I4, nArgs + 1);
            methodIL.Emit(OpCodes.Newarr, typeof(Object));
            methodIL.Emit(OpCodes.Stloc_0);


            methodIL.Emit(OpCodes.Ldloc_0);
            methodIL.Emit(OpCodes.Ldc_I4, 0);
            methodIL.Emit(OpCodes.Ldarg_0);
            methodIL.Emit(OpCodes.Stelem_Ref);

            for (int j = 0; j < nArgs; j++)
            {
                methodIL.Emit(OpCodes.Ldloc_0);
                methodIL.Emit(OpCodes.Ldc_I4, j + 1);
                methodIL.Emit(OpCodes.Ldarg, j + 1);
                if (methodHandle.args[j].GetType().IsValueType)
                {
                    methodIL.Emit(OpCodes.Box, methodHandle.args[j].GetType());
                }
                methodIL.Emit(OpCodes.Stelem_Ref);
            }
            methodIL.Emit(OpCodes.Ldloc_0);

            // invoke "invoke" in MethodHandle
            methodIL.Emit(OpCodes.Call, CallbackDelegate);


            if (methodHandle.type != null && !methodHandle.type.Equals(typeof(void)))
            {
                // if the return type if a value type, then unbox the return value
                // so that we don't get junk.
                if (methodHandle.type.IsValueType)
                {
                    methodIL.Emit(OpCodes.Unbox, methodHandle.type);
                    if (methodHandle.type.IsEnum)
                    {
                        methodIL.Emit(OpCodes.Ldind_I4);
                    }
                    else if (!methodHandle.type.IsPrimitive)
                    {
                        methodIL.Emit(OpCodes.Ldobj, methodHandle.type);
                    }
                    else
                    {
                        methodIL.Emit((OpCode)opCodeTypeMapper[methodHandle.type]);
                    }
                }
                else
                {
                    methodIL.Emit(OpCodes.Castclass, methodHandle.type);
                }

                // store the result
                methodIL.Emit(OpCodes.Stloc_1);
                // jump to the return statement
                methodIL.Emit(OpCodes.Br, returnLabel);
                // mark the return statement
                methodIL.MarkLabel(returnLabel);
                // load the value stored before we return.  This will either be
                // null (if the handler was null) or the return value from Invoke
                methodIL.Emit(OpCodes.Ldloc_1);
            }
            else
            {
                // pop the return value that Invoke returned from the stack since
                // the method's return type is void. 
                methodIL.Emit(OpCodes.Pop);
                //mark the return statement
                methodIL.MarkLabel(returnLabel);
            }

            // Return
            methodIL.Emit(OpCodes.Ret);

            return methodBuilder;
        }

        public static Type createType(String typeName, String[] properties, Type[] types)
        {
            if (typeCache.ContainsKey(typeName))
            {
                return typeCache[typeName];
            }

            TypeBuilder typeBuilder = getTypeBuilder(typeName, typeof(Object));

            typeBuilder.AddInterfaceImplementation(typeof(INotifyPropertyChanged));

            FieldBuilder eventBack = make_field(typeBuilder, "PropertyChanged", typeof(PropertyChangedEventHandler));

            MethodBuilder addPropertyChanged = make_AddPropertyChanged(typeBuilder, eventBack);
            MethodBuilder removePropertyChanged = make_RemovePropertyChanged(typeBuilder, eventBack);
            MethodBuilder raisePropertyChanged = make_RaisePropertyChanged(typeBuilder, eventBack);

            EventBuilder pcevent = typeBuilder.DefineEvent("PropertyChanged", EventAttributes.None, typeof(PropertyChangedEventHandler));
            pcevent.SetRaiseMethod(raisePropertyChanged);
            pcevent.SetAddOnMethod(addPropertyChanged);
            pcevent.SetRemoveOnMethod(removePropertyChanged);

            int nProperties = properties.Length;
            for (int i = 0; i < nProperties; i++)
            {
                PropertyDef p = PropertyDef.instance(properties[i], types[i], new AttributeDef[] { });
                make_property(typeBuilder, p, raisePropertyChanged);
            }

            Type type = typeBuilder.CreateType();
            typeCache.Add(typeName, type);
            Net.cacheType(typeName, type);

            asmBuilder.Save("test.dll");
            return type;
        }
    }
}
