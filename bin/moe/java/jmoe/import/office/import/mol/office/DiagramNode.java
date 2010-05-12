package mol.office  ;

import com4j.*;

@IID("{000C0370-0000-0000-C000-000000000046}")
public interface DiagramNode extends mol.office._IMsoDispObj {
    @VTID(9)
    mol.office.DiagramNode addNode(
        mol.office.MsoRelativeNodePosition pos,
        mol.office.MsoDiagramNodeType nodeType);

    @VTID(10)
    void delete();

    @VTID(11)
    void moveNode(
        mol.office.DiagramNode targetNode,
        mol.office.MsoRelativeNodePosition pos);

    @VTID(12)
    void replaceNode(
        mol.office.DiagramNode targetNode);

    @VTID(13)
    void swapNode(
        mol.office.DiagramNode targetNode,
        boolean swapChildren);

    @VTID(14)
    mol.office.DiagramNode cloneNode(
        boolean copyChildren,
        mol.office.DiagramNode targetNode,
        mol.office.MsoRelativeNodePosition pos);

    @VTID(15)
    void transferChildren(
        mol.office.DiagramNode receivingNode);

    @VTID(16)
    mol.office.DiagramNode nextNode();

    @VTID(17)
    mol.office.DiagramNode prevNode();

    @VTID(18)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(19)
    mol.office.DiagramNodeChildren children();

    @VTID(19)
    @ReturnValue(defaultPropertyThrough={mol.office.DiagramNodeChildren.class})
    mol.office.DiagramNode children(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(20)
    mol.office.Shape shape();

    @VTID(21)
    mol.office.DiagramNode root();

    @VTID(22)
    mol.office.IMsoDiagram diagram();

    @VTID(23)
    mol.office.MsoOrgChartLayoutType layout();

    @VTID(24)
    void layout(
        mol.office.MsoOrgChartLayoutType type);

    @VTID(25)
    mol.office.Shape textShape();

}
