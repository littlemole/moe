using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Reflection;
using System.Reflection.Emit;
using System.Threading;

namespace org.oha7.dotnet
{
    public class Prototype
    {
        private static MethodInfo DelegateCombine = typeof(Delegate).GetMethod("Combine", new Type[] { typeof(Delegate), typeof(Delegate) });
        private static MethodInfo DelegateRemove = typeof(Delegate).GetMethod("Remove", new Type[] { typeof(Delegate), typeof(Delegate) });
        private static MethodInfo InvokeDelegate = typeof(PropertyChangedEventHandler).GetMethod("Invoke");
        private static ConstructorInfo CreateEventArgs = typeof(PropertyChangedEventArgs).GetConstructor(new Type[] { typeof(String) });
        private static MethodAttributes getSetAttr = MethodAttributes.Public | MethodAttributes.SpecialName | MethodAttributes.HideBySig;
        private static Dictionary<string, Type> typeCache = new Dictionary<string, Type>();

        private static AssemblyBuilder asmBuilder = null;

        private static ModuleBuilder getBuilder(String typeName)
        {
            asmBuilder = null;
            ModuleBuilder modBuilder = null;

            AssemblyName assemblyName = new AssemblyName();
            assemblyName.Name = typeName;

            AppDomain thisDomain = Thread.GetDomain();
            asmBuilder = thisDomain.DefineDynamicAssembly(
                            assemblyName,
                            AssemblyBuilderAccess.RunAndSave,"D:\\"
                           );

            modBuilder = asmBuilder.DefineDynamicModule(
                         asmBuilder.GetName().Name,
                         "test.dll"
                      );

            return modBuilder;
        }

        private static TypeBuilder getTypeBuilder(String typeName)
        {
            ModuleBuilder modBuilder = getBuilder(typeName);

            TypeBuilder typeBuilder = modBuilder.DefineType(typeName,
                TypeAttributes.Public |
                TypeAttributes.Class |
                TypeAttributes.AutoClass |
                TypeAttributes.AnsiClass |
                TypeAttributes.BeforeFieldInit |
                TypeAttributes.AutoLayout,
                typeof(object),
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

        private static void make_property(TypeBuilder typeBuilder, String name, Type type, MethodBuilder raisePropertyChanged)
        {
            FieldBuilder fieldBuilder = make_field(typeBuilder, /*"_" + */ name, type);

            PropertyBuilder propertyBuilder = typeBuilder.DefineProperty(
                name,
                System.Reflection.PropertyAttributes.HasDefault,
                type,
                null);

            MethodBuilder getter = getAccessor(typeBuilder, name, type, fieldBuilder);
            MethodBuilder setter = getSetter(typeBuilder, name, type, fieldBuilder, raisePropertyChanged);

            propertyBuilder.SetGetMethod(getter);
            propertyBuilder.SetSetMethod(setter);
        }

        public static Type createType(String typeName, String[] properties, Type[] types)
        {
            if (typeCache.ContainsKey(typeName))
            {
                return typeCache[typeName];
            }

            TypeBuilder typeBuilder = getTypeBuilder(typeName);

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
                make_property(typeBuilder, properties[i], types[i], raisePropertyChanged);
            }

            Type type = typeBuilder.CreateType();
            typeCache.Add(typeName, type);
            Net.cacheType(typeName, type);
            asmBuilder.Save("test.dll");
            return type;
        }

        public static void copyTo(Object src,Object dest)
        {
            Type destType = dest.GetType();
            Type srcType = src.GetType();

            PropertyInfo[] properties = destType.GetProperties();
            if (properties == null || properties.Length == 0)
            {
                properties = srcType.GetProperties();
            }

            for (int i = 0; i < properties.Length; i++)
            {
                try
                {
                    Object value = srcType.InvokeMember(properties[i].Name, BindingFlags.Instance | BindingFlags.Public | BindingFlags.GetProperty, null, src, new object[] { });
                    destType.InvokeMember(properties[i].Name, BindingFlags.Instance | BindingFlags.Public | BindingFlags.SetProperty, null, dest, new object[] { value });
                }
                catch (TargetInvocationException e)
                {
                    e.ToString();
                }
            }
        }
    }
}
