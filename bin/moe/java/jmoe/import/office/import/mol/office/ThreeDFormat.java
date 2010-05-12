package mol.office  ;

import com4j.*;

@IID("{000C0321-0000-0000-C000-000000000046}")
public interface ThreeDFormat extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void incrementRotationX(
        float increment);

    @VTID(11)
    void incrementRotationY(
        float increment);

    @VTID(12)
    void resetRotation();

    @VTID(13)
    void setThreeDFormat(
        mol.office.MsoPresetThreeDFormat presetThreeDFormat);

    @VTID(14)
    void setExtrusionDirection(
        mol.office.MsoPresetExtrusionDirection presetExtrusionDirection);

    @VTID(15)
    float depth();

    @VTID(16)
    void depth(
        float depth);

    @VTID(17)
    mol.office.ColorFormat extrusionColor();

    @VTID(18)
    mol.office.MsoExtrusionColorType extrusionColorType();

    @VTID(19)
    void extrusionColorType(
        mol.office.MsoExtrusionColorType extrusionColorType);

    @VTID(20)
    mol.office.MsoTriState perspective();

    @VTID(21)
    void perspective(
        mol.office.MsoTriState perspective);

    @VTID(22)
    mol.office.MsoPresetExtrusionDirection presetExtrusionDirection();

    @VTID(23)
    mol.office.MsoPresetLightingDirection presetLightingDirection();

    @VTID(24)
    void presetLightingDirection(
        mol.office.MsoPresetLightingDirection presetLightingDirection);

    @VTID(25)
    mol.office.MsoPresetLightingSoftness presetLightingSoftness();

    @VTID(26)
    void presetLightingSoftness(
        mol.office.MsoPresetLightingSoftness presetLightingSoftness);

    @VTID(27)
    mol.office.MsoPresetMaterial presetMaterial();

    @VTID(28)
    void presetMaterial(
        mol.office.MsoPresetMaterial presetMaterial);

    @VTID(29)
    mol.office.MsoPresetThreeDFormat presetThreeDFormat();

    @VTID(30)
    float rotationX();

    @VTID(31)
    void rotationX(
        float rotationX);

    @VTID(32)
    float rotationY();

    @VTID(33)
    void rotationY(
        float rotationY);

    @VTID(34)
    mol.office.MsoTriState visible();

    @VTID(35)
    void visible(
        mol.office.MsoTriState visible);

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
        mol.office.MsoLightRigType presetLightRigType);

    @VTID(42)
    float z();

    @VTID(43)
    void z(
        float z);

    @VTID(44)
    mol.office.MsoBevelType bevelTopType();

    @VTID(45)
    void bevelTopType(
        mol.office.MsoBevelType bevelTopType);

    @VTID(46)
    float bevelTopInset();

    @VTID(47)
    void bevelTopInset(
        float bevelTopInset);

    @VTID(48)
    float bevelTopDepth();

    @VTID(49)
    void bevelTopDepth(
        float bevelTopDepth);

    @VTID(50)
    mol.office.MsoBevelType bevelBottomType();

    @VTID(51)
    void bevelBottomType(
        mol.office.MsoBevelType bevelBottomType);

    @VTID(52)
    float bevelBottomInset();

    @VTID(53)
    void bevelBottomInset(
        float bevelBottomInset);

    @VTID(54)
    float bevelBottomDepth();

    @VTID(55)
    void bevelBottomDepth(
        float bevelBottomDepth);

    @VTID(56)
    mol.office.MsoPresetCamera presetCamera();

    @VTID(57)
    float rotationZ();

    @VTID(58)
    void rotationZ(
        float rotationZ);

    @VTID(59)
    float contourWidth();

    @VTID(60)
    void contourWidth(
        float width);

    @VTID(61)
    mol.office.ColorFormat contourColor();

    @VTID(62)
    float fieldOfView();

    @VTID(63)
    void fieldOfView(
        float fov);

    @VTID(64)
    mol.office.MsoTriState projectText();

    @VTID(65)
    void projectText(
        mol.office.MsoTriState projectText);

    @VTID(66)
    float lightAngle();

    @VTID(67)
    void lightAngle(
        float lightAngle);

}
