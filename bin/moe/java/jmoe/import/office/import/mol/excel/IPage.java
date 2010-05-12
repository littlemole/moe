package mol.excel  ;

import com4j.*;

@IID("{000244A2-0001-0000-C000-000000000046}")
public interface IPage extends Com4jObject {
    @VTID(7)
    mol.excel.HeaderFooter leftHeader();

    @VTID(8)
    mol.excel.HeaderFooter centerHeader();

    @VTID(9)
    mol.excel.HeaderFooter rightHeader();

    @VTID(10)
    mol.excel.HeaderFooter leftFooter();

    @VTID(11)
    mol.excel.HeaderFooter centerFooter();

    @VTID(12)
    mol.excel.HeaderFooter rightFooter();

}
