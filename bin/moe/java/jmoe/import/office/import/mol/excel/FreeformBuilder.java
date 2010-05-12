package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface FreeformBuilder extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1762)
    void addNodes(
        mol.office.MsoSegmentType segmentType,
        mol.office.MsoEditingType editingType,
        float x1,
        float y1,
        java.lang.Object x2,
        java.lang.Object y2,
        java.lang.Object x3,
        java.lang.Object y3);

    @DISPID(1766)
    mol.excel.Shape convertToShape();

}
