package mol.word  ;

import com4j.*;

@IID("{00020956-0000-0000-C000-000000000046}")
public interface DropCap extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdDropPosition position();

    @VTID(11)
    void position(
        mol.word.WdDropPosition prop);

    @VTID(12)
    java.lang.String fontName();

    @VTID(13)
    void fontName(
        java.lang.String prop);

    @VTID(14)
    int linesToDrop();

    @VTID(15)
    void linesToDrop(
        int prop);

    @VTID(16)
    float distanceFromText();

    @VTID(17)
    void distanceFromText(
        float prop);

    @VTID(18)
    void clear();

    @VTID(19)
    void enable();

}
