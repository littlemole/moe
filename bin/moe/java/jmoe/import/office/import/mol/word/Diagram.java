package mol.word  ;

import com4j.*;

@IID("{000209EC-0000-0000-C000-000000000046}")
public interface Diagram extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.DiagramNodes nodes();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.word.DiagramNodes.class})
    mol.word.DiagramNode nodes(
        java.lang.Object index);

    @VTID(11)
    mol.office.MsoDiagramType type();

    @VTID(12)
    mol.office.MsoTriState autoLayout();

    @VTID(13)
    void autoLayout(
        mol.office.MsoTriState prop);

    @VTID(14)
    mol.office.MsoTriState reverse();

    @VTID(15)
    void reverse(
        mol.office.MsoTriState prop);

    @VTID(16)
    mol.office.MsoTriState autoFormat();

    @VTID(17)
    void autoFormat(
        mol.office.MsoTriState prop);

    @VTID(18)
    void convert(
        mol.office.MsoDiagramType type);

    @VTID(19)
    void fitText();

}
