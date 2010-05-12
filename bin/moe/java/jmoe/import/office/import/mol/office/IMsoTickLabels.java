package mol.office  ;

import com4j.*;

@IID("{000C1726-0000-0000-C000-000000000046}")
public interface IMsoTickLabels extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(9)
    mol.office.ChartFont font();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    java.lang.String numberFormat();

    @VTID(12)
    void numberFormat(
        java.lang.String pval);

    @VTID(13)
    boolean numberFormatLinked();

    @VTID(14)
    void numberFormatLinked(
        boolean pval);

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormatLocal();

    @VTID(16)
    void numberFormatLocal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pval);

    @VTID(17)
    mol.office.XlTickLabelOrientation orientation();

    @VTID(18)
    void orientation(
        mol.office.XlTickLabelOrientation pval);

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(20)
    int readingOrder();

    @VTID(21)
    void readingOrder(
        int pval);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(23)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pval);

    @VTID(24)
    int depth();

    @VTID(25)
    int offset();

    @VTID(26)
    void offset(
        int pval);

    @VTID(27)
    int alignment();

    @VTID(28)
    void alignment(
        int pval);

    @VTID(29)
    boolean multiLevel();

    @VTID(30)
    void multiLevel(
        boolean pval);

    @VTID(31)
    mol.office.IMsoChartFormat format();

}
