package mol.excel  ;

import com4j.*;

@IID("{000244A0-0001-0000-C000-000000000046}")
public interface IRanges extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    mol.excel.Range _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    mol.excel.Range item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    int count();

}
