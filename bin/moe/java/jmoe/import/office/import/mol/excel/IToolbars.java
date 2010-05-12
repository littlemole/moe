package mol.excel  ;

import com4j.*;

@IID("{0002085D-0001-0000-C000-000000000046}")
public interface IToolbars extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Toolbar add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name);

    @VTID(11)
    int count();

    @VTID(12)
    @DefaultMethod
    mol.excel.Toolbar _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    mol.excel.Toolbar item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

}
