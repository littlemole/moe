package mol.excel  ;

import com4j.*;

@IID("{00024434-0001-0000-C000-000000000046}")
public interface IFilter extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean on();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object criteria1();

    @VTID(12)
    mol.excel.XlAutoFilterOperator _Operator();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object criteria2();

    @VTID(14)
    mol.excel.XlAutoFilterOperator operator();

    @VTID(15)
    void operator(
        mol.excel.XlAutoFilterOperator rhs);

    @VTID(16)
    int count();

}
