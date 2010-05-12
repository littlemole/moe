package mol.word  ;

import com4j.*;

@IID("{00020972-0000-0000-C000-000000000046}")
public interface LineNumbering extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdNumberingRule restartMode();

    @VTID(11)
    void restartMode(
        mol.word.WdNumberingRule prop);

    @VTID(12)
    int startingNumber();

    @VTID(13)
    void startingNumber(
        int prop);

    @VTID(14)
    float distanceFromText();

    @VTID(15)
    void distanceFromText(
        float prop);

    @VTID(16)
    int countBy();

    @VTID(17)
    void countBy(
        int prop);

    @VTID(18)
    int active();

    @VTID(19)
    void active(
        int prop);

}
