package mol.office  ;

import com4j.*;

@IID("{000C0311-0000-0000-C000-000000000046}")
public interface CalloutFormat extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void automaticLength();

    @VTID(11)
    void customDrop(
        float drop);

    @VTID(12)
    void customLength(
        float length);

    @VTID(13)
    void presetDrop(
        mol.office.MsoCalloutDropType dropType);

    @VTID(14)
    mol.office.MsoTriState accent();

    @VTID(15)
    void accent(
        mol.office.MsoTriState accent);

    @VTID(16)
    mol.office.MsoCalloutAngleType angle();

    @VTID(17)
    void angle(
        mol.office.MsoCalloutAngleType angle);

    @VTID(18)
    mol.office.MsoTriState autoAttach();

    @VTID(19)
    void autoAttach(
        mol.office.MsoTriState autoAttach);

    @VTID(20)
    mol.office.MsoTriState autoLength();

    @VTID(21)
    mol.office.MsoTriState border();

    @VTID(22)
    void border(
        mol.office.MsoTriState border);

    @VTID(23)
    float drop();

    @VTID(24)
    mol.office.MsoCalloutDropType dropType();

    @VTID(25)
    float gap();

    @VTID(26)
    void gap(
        float gap);

    @VTID(27)
    float length();

    @VTID(28)
    mol.office.MsoCalloutType type();

    @VTID(29)
    void type(
        mol.office.MsoCalloutType type);

}
