package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DataTable extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(171)
    @PropGet
    boolean showLegendKey();

    @DISPID(171)
    @PropPut
    void showLegendKey(
        boolean rhs);

    @DISPID(1671)
    @PropGet
    boolean hasBorderHorizontal();

    @DISPID(1671)
    @PropPut
    void hasBorderHorizontal(
        boolean rhs);

    @DISPID(1672)
    @PropGet
    boolean hasBorderVertical();

    @DISPID(1672)
    @PropPut
    void hasBorderVertical(
        boolean rhs);

    @DISPID(1673)
    @PropGet
    boolean hasBorderOutline();

    @DISPID(1673)
    @PropPut
    void hasBorderOutline(
        boolean rhs);

    @DISPID(128)
    @PropGet
    mol.excel.Border border();

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(235)
    void select();

    @DISPID(117)
    void delete();

    @DISPID(1525)
    @PropGet
    java.lang.Object autoScaleFont();

    @DISPID(1525)
    @PropPut
    void autoScaleFont(
        java.lang.Object rhs);

    @DISPID(116)
    @PropGet
    mol.excel.ChartFormat format();

}
