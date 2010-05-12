package mol.office  ;

import com4j.*;

@IID("{000C0320-0000-0000-C000-000000000046}")
public interface TextFrame extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    float marginBottom();

    @VTID(11)
    void marginBottom(
        float marginBottom);

    @VTID(12)
    float marginLeft();

    @VTID(13)
    void marginLeft(
        float marginLeft);

    @VTID(14)
    float marginRight();

    @VTID(15)
    void marginRight(
        float marginRight);

    @VTID(16)
    float marginTop();

    @VTID(17)
    void marginTop(
        float marginTop);

    @VTID(18)
    mol.office.MsoTextOrientation orientation();

    @VTID(19)
    void orientation(
        mol.office.MsoTextOrientation orientation);

}
