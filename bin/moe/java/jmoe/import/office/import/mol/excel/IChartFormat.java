package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;


@IID("{000244B2-0001-0000-C000-000000000046}")
public interface IChartFormat extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.FillFormat fill();

    @VTID(11)
    mol.office.GlowFormat glow();

    @VTID(12)
    mol.excel.LineFormat line();

    @VTID(13)
    mol.excel.PictureFormat pictureFormat();

    @VTID(14)
    mol.excel.ShadowFormat shadow();

    @VTID(15)
    mol.office.SoftEdgeFormat softEdge();

    @VTID(16)
    mol.excel.TextFrame2 textFrame2();

    @VTID(17)
    mol.excel.ThreeDFormat threeD();

}
