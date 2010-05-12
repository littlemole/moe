package mol.excel  ;

import com4j.*;

@IID("{00024422-0001-0000-C000-000000000046}")
public interface ICustomViews extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.CustomView item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object viewName);

    @VTID(12)
    mol.excel.CustomView add(
        java.lang.String viewName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printSettings,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowColSettings);

    @VTID(13)
    @DefaultMethod
    mol.excel.CustomView _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object viewName);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

}
