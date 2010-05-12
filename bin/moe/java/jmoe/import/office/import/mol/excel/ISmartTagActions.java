package mol.excel  ;

import com4j.*;

@IID("{0002445F-0001-0000-C000-000000000046}")
public interface ISmartTagActions extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    mol.excel.SmartTagAction _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    mol.excel.SmartTagAction item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

}
