package mol.excel  ;

import com4j.*;

@IID("{0002441E-0001-0000-C000-000000000046}")
public interface IPivotFormula extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void delete();

    @VTID(11)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(12)
    @DefaultMethod
    void _Default(
        java.lang.String rhs);

    @VTID(13)
    java.lang.String formula();

    @VTID(14)
    void formula(
        java.lang.String rhs);

    @VTID(15)
    java.lang.String value();

    @VTID(16)
    void value(
        java.lang.String rhs);

    @VTID(17)
    int index();

    @VTID(18)
    void index(
        int rhs);

    @VTID(19)
    java.lang.String standardFormula();

    @VTID(20)
    void standardFormula(
        java.lang.String rhs);

}
