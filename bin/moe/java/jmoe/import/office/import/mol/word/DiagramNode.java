package mol.word  ;

import com4j.*;

@IID("{000209E9-0000-0000-C000-000000000046}")
public interface DiagramNode extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.DiagramNodeChildren children();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.word.DiagramNodeChildren.class})
    mol.word.DiagramNode children(
        java.lang.Object index);

    @VTID(11)
    mol.word.Shape shape();

    @VTID(12)
    mol.word.DiagramNode root();

    @VTID(13)
    mol.word.Diagram diagram();

    @VTID(14)
    mol.office.MsoOrgChartLayoutType layout();

    @VTID(15)
    void layout(
        mol.office.MsoOrgChartLayoutType prop);

    @VTID(16)
    mol.word.Shape textShape();

    @VTID(17)
    mol.word.DiagramNode addNode(
        mol.office.MsoRelativeNodePosition pos,
        mol.office.MsoDiagramNodeType nodeType);

    @VTID(18)
    void delete();

    @VTID(19)
    @ReturnValue(index=0)
    mol.word.DiagramNode moveNode(
        mol.office.MsoRelativeNodePosition pos);

    @VTID(20)
    mol.word.DiagramNode replaceNode();

    @VTID(21)
    @ReturnValue(index=0)
    mol.word.DiagramNode swapNode(
        mol.office.MsoRelativeNodePosition pos);

    @VTID(22)
    mol.word.DiagramNode cloneNode(
        boolean copyChildren,
        Holder<mol.word.DiagramNode> targetNode,
        mol.office.MsoRelativeNodePosition pos);

    @VTID(23)
    mol.word.DiagramNode transferChildren();

    @VTID(24)
    mol.word.DiagramNode nextNode();

    @VTID(25)
    mol.word.DiagramNode prevNode();

}
