package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Diagram extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1701)
    @PropGet
    mol.excel.DiagramNodes nodes();

    @DISPID(108)
    @PropGet
    mol.office.MsoDiagramType type();

    @DISPID(2243)
    @PropGet
    mol.office.MsoTriState autoLayout();

    @DISPID(2243)
    @PropPut
    void autoLayout(
        mol.office.MsoTriState rhs);

    @DISPID(2244)
    @PropGet
    mol.office.MsoTriState reverse();

    @DISPID(2244)
    @PropPut
    void reverse(
        mol.office.MsoTriState rhs);

    @DISPID(114)
    @PropGet
    mol.office.MsoTriState autoFormat();

    @DISPID(114)
    @PropPut
    void autoFormat(
        mol.office.MsoTriState rhs);

    @DISPID(1046)
    void convert(
        mol.office.MsoDiagramType type);

    @DISPID(2304)
    void fitText();

}
