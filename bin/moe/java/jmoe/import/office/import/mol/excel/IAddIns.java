package mol.excel  ;

import com4j.*;

@IID("{00020858-0001-0000-C000-000000000046}")
public interface IAddIns extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.AddIn add(
        java.lang.String filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copyFile);

    @VTID(11)
    int count();

    @VTID(12)
    mol.excel.AddIn item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(14)
    @DefaultMethod
    mol.excel.AddIn _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
