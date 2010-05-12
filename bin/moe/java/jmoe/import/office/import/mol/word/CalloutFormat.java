package mol.word  ;

import com4j.*;

@IID("{000209C5-0000-0000-C000-000000000046}")
public interface CalloutFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.MsoTriState accent();

    @VTID(11)
    void accent(
        mol.office.MsoTriState prop);

    @VTID(12)
    mol.office.MsoCalloutAngleType angle();

    @VTID(13)
    void angle(
        mol.office.MsoCalloutAngleType prop);

    @VTID(14)
    mol.office.MsoTriState autoAttach();

    @VTID(15)
    void autoAttach(
        mol.office.MsoTriState prop);

    @VTID(16)
    mol.office.MsoTriState autoLength();

    @VTID(17)
    mol.office.MsoTriState border();

    @VTID(18)
    void border(
        mol.office.MsoTriState prop);

    @VTID(19)
    float drop();

    @VTID(20)
    mol.office.MsoCalloutDropType dropType();

    @VTID(21)
    float gap();

    @VTID(22)
    void gap(
        float prop);

    @VTID(23)
    float length();

    @VTID(24)
    mol.office.MsoCalloutType type();

    @VTID(25)
    void type(
        mol.office.MsoCalloutType prop);

    @VTID(26)
    void automaticLength();

    @VTID(27)
    void customDrop(
        float drop);

    @VTID(28)
    void customLength(
        float length);

    @VTID(29)
    void presetDrop(
        mol.office.MsoCalloutDropType dropType);

}
