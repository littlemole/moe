package mol.word  ;

import com4j.*;

@IID("{000209C3-0000-0000-C000-000000000046}")
public interface WrapFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdWrapType type();

    @VTID(11)
    void type(
        mol.word.WdWrapType prop);

    @VTID(12)
    mol.word.WdWrapSideType side();

    @VTID(13)
    void side(
        mol.word.WdWrapSideType prop);

    @VTID(14)
    float distanceTop();

    @VTID(15)
    void distanceTop(
        float prop);

    @VTID(16)
    float distanceBottom();

    @VTID(17)
    void distanceBottom(
        float prop);

    @VTID(18)
    float distanceLeft();

    @VTID(19)
    void distanceLeft(
        float prop);

    @VTID(20)
    float distanceRight();

    @VTID(21)
    void distanceRight(
        float prop);

    @VTID(22)
    int allowOverlap();

    @VTID(23)
    void allowOverlap(
        int prop);

}
