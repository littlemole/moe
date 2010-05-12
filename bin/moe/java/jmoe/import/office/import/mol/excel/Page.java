package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Page extends Com4jObject {
    @DISPID(1018)
    @PropGet
    mol.excel.HeaderFooter leftHeader();

    @DISPID(1011)
    @PropGet
    mol.excel.HeaderFooter centerHeader();

    @DISPID(1026)
    @PropGet
    mol.excel.HeaderFooter rightHeader();

    @DISPID(1017)
    @PropGet
    mol.excel.HeaderFooter leftFooter();

    @DISPID(1010)
    @PropGet
    mol.excel.HeaderFooter centerFooter();

    @DISPID(1025)
    @PropGet
    mol.excel.HeaderFooter rightFooter();

}
