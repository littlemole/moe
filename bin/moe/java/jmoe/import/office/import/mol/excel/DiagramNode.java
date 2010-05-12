package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{000C0370-0000-0000-C000-000000000046}")
public interface DiagramNode extends mol.office._IMsoDispObj {
    @VTID(9)
    mol.excel.DiagramNode addNode(
        mol.office.MsoRelativeNodePosition pos,
        mol.office.MsoDiagramNodeType nodeType);

    @VTID(10)
    void delete();

    @VTID(11)
    void moveNode(
        mol.excel.DiagramNode pTargetNode,
        mol.office.MsoRelativeNodePosition pos);

    @VTID(12)
    void replaceNode(
        mol.excel.DiagramNode pTargetNode);

    @VTID(13)
    void swapNode(
        mol.excel.DiagramNode pTargetNode,
        boolean swapChildren);

    @VTID(14)
    mol.excel.DiagramNode cloneNode(
        boolean copyChildren,
        mol.excel.DiagramNode pTargetNode,
        mol.office.MsoRelativeNodePosition pos);

    @VTID(15)
    void transferChildren(
        mol.excel.DiagramNode pReceivingNode);

    @VTID(16)
    mol.excel.DiagramNode nextNode();

    @VTID(17)
    mol.excel.DiagramNode prevNode();

    @VTID(18)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(19)
    mol.excel.DiagramNodeChildren children();

    @VTID(19)
    @ReturnValue(defaultPropertyThrough={mol.excel.DiagramNodeChildren.class})
    mol.excel.DiagramNode children(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(20)
    mol.excel.Shape shape();

    @VTID(21)
    mol.excel.DiagramNode root();

    @VTID(22)
    mol.office.IMsoDiagram diagram();

    @VTID(23)
    mol.office.MsoOrgChartLayoutType layout();

    @VTID(24)
    void layout(
        mol.office.MsoOrgChartLayoutType pdgmType);

    @VTID(25)
    mol.excel.Shape textShape();

}
