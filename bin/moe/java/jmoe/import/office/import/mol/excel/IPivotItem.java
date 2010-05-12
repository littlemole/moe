package mol.excel  ;

import com4j.*;

@IID("{00020876-0001-0000-C000-000000000046}")
public interface IPivotItem extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    mol.excel.PivotField parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object childItems(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    mol.excel.Range dataRange();

    @VTID(12)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(13)
    @DefaultMethod
    void _Default(
        java.lang.String rhs);

    @VTID(14)
    mol.excel.Range labelRange();

    @VTID(15)
    java.lang.String name();

    @VTID(16)
    void name(
        java.lang.String rhs);

    @VTID(17)
    mol.excel.PivotItem parentItem();

    @VTID(18)
    boolean parentShowDetail();

    @VTID(19)
    int position();

    @VTID(20)
    void position(
        int rhs);

    @VTID(21)
    boolean showDetail();

    @VTID(22)
    void showDetail(
        boolean rhs);

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object sourceName();

    @VTID(24)
    java.lang.String value();

    @VTID(25)
    void value(
        java.lang.String rhs);

    @VTID(26)
    boolean visible();

    @VTID(27)
    void visible(
        boolean rhs);

    @VTID(28)
    void delete();

    @VTID(29)
    boolean isCalculated();

    @VTID(30)
    int recordCount();

    @VTID(31)
    java.lang.String formula();

    @VTID(32)
    void formula(
        java.lang.String rhs);

    @VTID(33)
    java.lang.String caption();

    @VTID(34)
    void caption(
        java.lang.String rhs);

    @VTID(35)
    boolean drilledDown();

    @VTID(36)
    void drilledDown(
        boolean rhs);

    @VTID(37)
    java.lang.String standardFormula();

    @VTID(38)
    void standardFormula(
        java.lang.String rhs);

    @VTID(39)
    java.lang.String sourceNameStandard();

    @VTID(40)
    void drillTo(
        java.lang.String field);

}
