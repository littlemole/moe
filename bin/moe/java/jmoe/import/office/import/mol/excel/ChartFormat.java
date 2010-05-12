package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ChartFormat extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1663)
    @PropGet
    mol.excel.FillFormat fill();

    @DISPID(2663)
    @PropGet
    mol.office.GlowFormat glow();

    @DISPID(817)
    @PropGet
    mol.excel.LineFormat line();

    @DISPID(1631)
    @PropGet
    mol.excel.PictureFormat pictureFormat();

    @DISPID(103)
    @PropGet
    mol.excel.ShadowFormat shadow();

    @DISPID(2662)
    @PropGet
    mol.office.SoftEdgeFormat softEdge();

    @DISPID(2659)
    @PropGet
    mol.excel.TextFrame2 textFrame2();

    @DISPID(1703)
    @PropGet
    mol.excel.ThreeDFormat threeD();

}
