package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface SmartTagOptions extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2218)
    @PropGet
    mol.excel.XlSmartTagDisplayMode displaySmartTags();

    @DISPID(2218)
    @PropPut
    void displaySmartTags(
        mol.excel.XlSmartTagDisplayMode rhs);

    @DISPID(2219)
    @PropGet
    boolean embedSmartTags();

    @DISPID(2219)
    @PropPut
    void embedSmartTags(
        boolean rhs);

}
