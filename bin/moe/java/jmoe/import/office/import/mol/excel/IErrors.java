package mol.excel  ;

import com4j.*;

@IID("{0002445C-0001-0000-C000-000000000046}")
public interface IErrors extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Error item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    @DefaultMethod
    mol.excel.Error _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
