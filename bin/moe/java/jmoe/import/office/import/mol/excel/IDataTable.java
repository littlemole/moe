package mol.excel  ;

import com4j.*;

@IID("{00020843-0001-0000-C000-000000000046}")
public interface IDataTable extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean showLegendKey();

    @VTID(11)
    void showLegendKey(
        boolean rhs);

    @VTID(12)
    boolean hasBorderHorizontal();

    @VTID(13)
    void hasBorderHorizontal(
        boolean rhs);

    @VTID(14)
    boolean hasBorderVertical();

    @VTID(15)
    void hasBorderVertical(
        boolean rhs);

    @VTID(16)
    boolean hasBorderOutline();

    @VTID(17)
    void hasBorderOutline(
        boolean rhs);

    @VTID(18)
    mol.excel.Border border();

    @VTID(19)
    mol.excel.Font font();

    @VTID(20)
    void select();

    @VTID(21)
    void delete();

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object autoScaleFont();

    @VTID(23)
    void autoScaleFont(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(24)
    mol.excel.ChartFormat format();

}
