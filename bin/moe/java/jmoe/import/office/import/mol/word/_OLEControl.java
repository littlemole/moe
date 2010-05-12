package mol.word  ;

import com4j.*;

@IID("{000209A4-0000-0000-C000-000000000046}")
public interface _OLEControl extends Com4jObject {
    @VTID(7)
    float left();

    @VTID(8)
    void left(
        float prop);

    @VTID(9)
    float top();

    @VTID(10)
    void top(
        float prop);

    @VTID(11)
    float height();

    @VTID(12)
    void height(
        float prop);

    @VTID(13)
    float width();

    @VTID(14)
    void width(
        float prop);

    @VTID(15)
    java.lang.String name();

    @VTID(16)
    void name(
        java.lang.String prop);

    @VTID(17)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject automation();

    @VTID(18)
    void select();

    @VTID(19)
    void copy();

    @VTID(20)
    void cut();

    @VTID(21)
    void delete();

    @VTID(22)
    void activate();

    @VTID(23)
    java.lang.String altHTML();

    @VTID(24)
    void altHTML(
        java.lang.String prop);

}
