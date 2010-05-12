package mol.office  ;

import com4j.*;

@IID("{000C03B9-0000-0000-C000-000000000046}")
public interface BulletFormat2 extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int character();

    @VTID(11)
    void character(
        int character);

    @VTID(12)
    mol.office.Font2 font();

    @VTID(13)
    int number();

    @VTID(14)
    void picture(
        java.lang.String fileName);

    @VTID(15)
    float relativeSize();

    @VTID(16)
    void relativeSize(
        float size);

    @VTID(17)
    int startValue();

    @VTID(18)
    void startValue(
        int start);

    @VTID(19)
    mol.office.MsoNumberedBulletStyle style();

    @VTID(20)
    void style(
        mol.office.MsoNumberedBulletStyle style);

    @VTID(21)
    mol.office.MsoBulletType type();

    @VTID(22)
    void type(
        mol.office.MsoBulletType type);

    @VTID(23)
    mol.office.MsoTriState useTextColor();

    @VTID(24)
    void useTextColor(
        mol.office.MsoTriState useTextColor);

    @VTID(25)
    mol.office.MsoTriState useTextFont();

    @VTID(26)
    void useTextFont(
        mol.office.MsoTriState useTextFont);

    @VTID(27)
    mol.office.MsoTriState visible();

    @VTID(28)
    void visible(
        mol.office.MsoTriState visible);

}
