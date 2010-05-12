package mol.excel  ;

import com4j.*;

@IID("{000208C9-0001-0000-C000-000000000046}")
public interface ITickLabels extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(11)
    mol.excel.Font font();

    @VTID(12)
    java.lang.String name();

    @VTID(13)
    java.lang.String numberFormat();

    @VTID(14)
    void numberFormat(
        java.lang.String rhs);

    @VTID(15)
    boolean numberFormatLinked();

    @VTID(16)
    void numberFormatLinked(
        boolean rhs);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormatLocal();

    @VTID(18)
    void numberFormatLocal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(19)
    mol.excel.XlTickLabelOrientation orientation();

    @VTID(20)
    void orientation(
        mol.excel.XlTickLabelOrientation rhs);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(22)
    int readingOrder();

    @VTID(23)
    void readingOrder(
        int rhs);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(25)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(26)
    int depth();

    @VTID(27)
    int offset();

    @VTID(28)
    void offset(
        int rhs);

    @VTID(29)
    int alignment();

    @VTID(30)
    void alignment(
        int rhs);

    @VTID(31)
    boolean multiLevel();

    @VTID(32)
    void multiLevel(
        boolean rhs);

    @VTID(33)
    mol.excel.ChartFormat format();

}
