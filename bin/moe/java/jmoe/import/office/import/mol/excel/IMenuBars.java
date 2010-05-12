package mol.excel  ;

import com4j.*;

@IID("{00020863-0001-0000-C000-000000000046}")
public interface IMenuBars extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.MenuBar add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name);

    @VTID(11)
    int count();

    @VTID(12)
    @DefaultMethod
    mol.excel.MenuBar _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    mol.excel.MenuBar item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

}
