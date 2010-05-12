package mol.office  ;

import com4j.*;

@IID("{000C036D-0000-0000-C000-000000000046}")
public interface IMsoDiagram extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.DiagramNodes nodes();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.office.DiagramNodes.class})
    mol.office.DiagramNode nodes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    mol.office.MsoDiagramType type();

    @VTID(12)
    mol.office.MsoTriState autoLayout();

    @VTID(13)
    void autoLayout(
        mol.office.MsoTriState autoLayout);

    @VTID(14)
    mol.office.MsoTriState reverse();

    @VTID(15)
    void reverse(
        mol.office.MsoTriState reverse);

    @VTID(16)
    mol.office.MsoTriState autoFormat();

    @VTID(17)
    void autoFormat(
        mol.office.MsoTriState autoFormat);

    @VTID(18)
    void convert(
        mol.office.MsoDiagramType type);

    @VTID(19)
    void fitText();

}
