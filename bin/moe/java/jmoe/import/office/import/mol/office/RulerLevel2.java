package mol.office  ;

import com4j.*;

@IID("{000C03C3-0000-0000-C000-000000000046}")
public interface RulerLevel2 extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    float firstMargin();

    @VTID(11)
    void firstMargin(
        float firstMargin);

    @VTID(12)
    float leftMargin();

    @VTID(13)
    void leftMargin(
        float leftMargin);

}
