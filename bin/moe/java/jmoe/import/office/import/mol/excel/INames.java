package mol.excel  ;

import com4j.*;

@IID("{000208B8-0001-0000-C000-000000000046}")
public interface INames extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Name add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object refersTo,
        @MarshalAs(NativeType.VARIANT) java.lang.Object visible,
        @MarshalAs(NativeType.VARIANT) java.lang.Object macroType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object shortcutKey,
        @MarshalAs(NativeType.VARIANT) java.lang.Object category,
        @MarshalAs(NativeType.VARIANT) java.lang.Object nameLocal,
        @MarshalAs(NativeType.VARIANT) java.lang.Object refersToLocal,
        @MarshalAs(NativeType.VARIANT) java.lang.Object categoryLocal,
        @MarshalAs(NativeType.VARIANT) java.lang.Object refersToR1C1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object refersToR1C1Local);

    @VTID(11)
    mol.excel.Name item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object indexLocal,
        @MarshalAs(NativeType.VARIANT) java.lang.Object refersTo,
        int lcid);

    @VTID(12)
    @DefaultMethod
    mol.excel.Name _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object indexLocal,
        @MarshalAs(NativeType.VARIANT) java.lang.Object refersTo,
        int lcid);

    @VTID(13)
    int count();

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

}
