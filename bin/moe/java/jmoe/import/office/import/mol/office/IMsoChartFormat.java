package mol.office  ;

import com4j.*;

@IID("{000C1730-0000-0000-C000-000000000046}")
public interface IMsoChartFormat extends Com4jObject {
    @VTID(7)
    mol.office.FillFormat fill();

    @VTID(8)
    mol.office.GlowFormat glow();

    @VTID(9)
    mol.office.LineFormat line();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    mol.office.PictureFormat pictureFormat();

    @VTID(12)
    mol.office.ShadowFormat shadow();

    @VTID(13)
    mol.office.SoftEdgeFormat softEdge();

    @VTID(14)
    mol.office.TextFrame2 textFrame2();

    @VTID(15)
    mol.office.ThreeDFormat threeD();

}
