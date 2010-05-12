package mol.excel  ;

import com4j.*;

@IID("{00024483-0001-0000-C000-000000000046}")
public interface IPivotFilter extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int order();

    @VTID(11)
    void order(
        int rhs);

    @VTID(12)
    mol.excel.XlPivotFilterType filterType();

    @VTID(13)
    java.lang.String name();

    @VTID(14)
    java.lang.String description();

    @VTID(15)
    void delete();

    @VTID(16)
    boolean active();

    @VTID(17)
    mol.excel.PivotField pivotField();

    @VTID(18)
    mol.excel.PivotField dataField();

    @VTID(19)
    mol.excel.CubeField dataCubeField();

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value1();

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value2();

    @VTID(22)
    mol.excel.PivotField memberPropertyField();

    @VTID(23)
    boolean isMemberPropertyFilter();

}
