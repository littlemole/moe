package mol.word  ;

import com4j.*;

@IID("{000209D0-0000-0000-C000-000000000046}")
public interface ThreeDFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    float depth();

    @VTID(11)
    void depth(
        float prop);

    @VTID(12)
    mol.word.ColorFormat extrusionColor();

    @VTID(13)
    mol.office.MsoExtrusionColorType extrusionColorType();

    @VTID(14)
    void extrusionColorType(
        mol.office.MsoExtrusionColorType prop);

    @VTID(15)
    mol.office.MsoTriState perspective();

    @VTID(16)
    void perspective(
        mol.office.MsoTriState prop);

    @VTID(17)
    mol.office.MsoPresetExtrusionDirection presetExtrusionDirection();

    @VTID(18)
    mol.office.MsoPresetLightingDirection presetLightingDirection();

    @VTID(19)
    void presetLightingDirection(
        mol.office.MsoPresetLightingDirection prop);

    @VTID(20)
    mol.office.MsoPresetLightingSoftness presetLightingSoftness();

    @VTID(21)
    void presetLightingSoftness(
        mol.office.MsoPresetLightingSoftness prop);

    @VTID(22)
    mol.office.MsoPresetMaterial presetMaterial();

    @VTID(23)
    void presetMaterial(
        mol.office.MsoPresetMaterial prop);

    @VTID(24)
    mol.office.MsoPresetThreeDFormat presetThreeDFormat();

    @VTID(25)
    float rotationX();

    @VTID(26)
    void rotationX(
        float prop);

    @VTID(27)
    float rotationY();

    @VTID(28)
    void rotationY(
        float prop);

    @VTID(29)
    mol.office.MsoTriState visible();

    @VTID(30)
    void visible(
        mol.office.MsoTriState prop);

    @VTID(31)
    void incrementRotationX(
        float increment);

    @VTID(32)
    void incrementRotationY(
        float increment);

    @VTID(33)
    void resetRotation();

    @VTID(34)
    void setExtrusionDirection(
        mol.office.MsoPresetExtrusionDirection presetExtrusionDirection);

    @VTID(35)
    void setThreeDFormat(
        mol.office.MsoPresetThreeDFormat presetThreeDFormat);

    @VTID(36)
    void setPresetCamera(
        mol.office.MsoPresetCamera presetCamera);

    @VTID(37)
    void incrementRotationZ(
        float increment);

    @VTID(38)
    void incrementRotationHorizontal(
        float increment);

    @VTID(39)
    void incrementRotationVertical(
        float increment);

    @VTID(40)
    mol.office.MsoLightRigType presetLighting();

    @VTID(41)
    void presetLighting(
        mol.office.MsoLightRigType prop);

    @VTID(42)
    float z();

    @VTID(43)
    void z(
        float prop);

    @VTID(44)
    mol.office.MsoBevelType bevelTopType();

    @VTID(45)
    void bevelTopType(
        mol.office.MsoBevelType prop);

    @VTID(46)
    float bevelTopInset();

    @VTID(47)
    void bevelTopInset(
        float prop);

    @VTID(48)
    float bevelTopDepth();

    @VTID(49)
    void bevelTopDepth(
        float prop);

    @VTID(50)
    mol.office.MsoBevelType bevelBottomType();

    @VTID(51)
    void bevelBottomType(
        mol.office.MsoBevelType prop);

    @VTID(52)
    float bevelBottomInset();

    @VTID(53)
    void bevelBottomInset(
        float prop);

    @VTID(54)
    float bevelBottomDepth();

    @VTID(55)
    void bevelBottomDepth(
        float prop);

    @VTID(56)
    mol.office.MsoPresetCamera presetCamera();

    @VTID(57)
    float rotationZ();

    @VTID(58)
    void rotationZ(
        float prop);

    @VTID(59)
    float contourWidth();

    @VTID(60)
    void contourWidth(
        float prop);

    @VTID(61)
    mol.word.ColorFormat contourColor();

    @VTID(62)
    float fieldOfView();

    @VTID(63)
    void fieldOfView(
        float prop);

    @VTID(64)
    mol.office.MsoTriState projectText();

    @VTID(65)
    void projectText(
        mol.office.MsoTriState prop);

    @VTID(66)
    float lightAngle();

    @VTID(67)
    void lightAngle(
        float prop);

}
