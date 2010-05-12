package mol.office  ;

import com4j.*;

@IID("{000C1711-0000-0000-C000-000000000046}")
public interface IMsoDataTable extends Com4jObject {
    @VTID(7)
    void showLegendKey(
        boolean pfVisible);

    @VTID(8)
    boolean showLegendKey();

    @VTID(9)
    void hasBorderHorizontal(
        boolean pfVisible);

    @VTID(10)
    boolean hasBorderHorizontal();

    @VTID(11)
    void hasBorderVertical(
        boolean pfVisible);

    @VTID(12)
    boolean hasBorderVertical();

    @VTID(13)
    void hasBorderOutline(
        boolean pfVisible);

    @VTID(14)
    boolean hasBorderOutline();

    @VTID(15)
    mol.office.IMsoBorder border();

    @VTID(16)
    mol.office.ChartFont font();

    @VTID(17)
    void select();

    @VTID(18)
    void delete();

    @VTID(19)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(21)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(22)
    mol.office.IMsoChartFormat format();

}
