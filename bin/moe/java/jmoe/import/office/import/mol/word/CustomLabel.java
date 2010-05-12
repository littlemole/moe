package mol.word  ;

import com4j.*;

@IID("{00020915-0000-0000-C000-000000000046}")
public interface CustomLabel extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int index();

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    void name(
        java.lang.String prop);

    @VTID(13)
    float topMargin();

    @VTID(14)
    void topMargin(
        float prop);

    @VTID(15)
    float sideMargin();

    @VTID(16)
    void sideMargin(
        float prop);

    @VTID(17)
    float height();

    @VTID(18)
    void height(
        float prop);

    @VTID(19)
    float width();

    @VTID(20)
    void width(
        float prop);

    @VTID(21)
    float verticalPitch();

    @VTID(22)
    void verticalPitch(
        float prop);

    @VTID(23)
    float horizontalPitch();

    @VTID(24)
    void horizontalPitch(
        float prop);

    @VTID(25)
    int numberAcross();

    @VTID(26)
    void numberAcross(
        int prop);

    @VTID(27)
    int numberDown();

    @VTID(28)
    void numberDown(
        int prop);

    @VTID(29)
    boolean dotMatrix();

    @VTID(30)
    mol.word.WdCustomLabelPageSize pageSize();

    @VTID(31)
    void pageSize(
        mol.word.WdCustomLabelPageSize prop);

    @VTID(32)
    boolean valid();

    @VTID(33)
    void delete();

}
