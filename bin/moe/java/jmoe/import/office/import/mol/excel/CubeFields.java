package mol.excel  ;

import com4j.*;

@IID("{0002444D-0000-0000-C000-000000000046}")
public interface CubeFields extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.CubeField item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    @DefaultMethod
    mol.excel.CubeField _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(14)
    mol.excel.CubeField addSet(
        java.lang.String name,
        java.lang.String caption);

}
