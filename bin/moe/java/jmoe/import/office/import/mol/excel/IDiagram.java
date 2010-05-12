package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{0002446F-0001-0000-C000-000000000046}")
public interface IDiagram extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.DiagramNodes nodes();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.excel.DiagramNodes.class})
    mol.excel.DiagramNode nodes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    mol.office.MsoDiagramType type();

    @VTID(12)
    mol.office.MsoTriState autoLayout();

    @VTID(13)
    void autoLayout(
        mol.office.MsoTriState rhs);

    @VTID(14)
    mol.office.MsoTriState reverse();

    @VTID(15)
    void reverse(
        mol.office.MsoTriState rhs);

    @VTID(16)
    mol.office.MsoTriState autoFormat();

    @VTID(17)
    void autoFormat(
        mol.office.MsoTriState rhs);

    @VTID(18)
    void convert(
        mol.office.MsoDiagramType type);

    @VTID(19)
    void fitText();

}
