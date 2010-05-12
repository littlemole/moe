package mol.office  ;

import com4j.*;

@IID("{000C0398-0000-0000-C000-000000000046}")
public interface TextFrame2 extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    float marginBottom();

    @VTID(11)
    void marginBottom(
        float marginBottom);

    @VTID(12)
    float marginLeft();

    @VTID(13)
    void marginLeft(
        float marginLeft);

    @VTID(14)
    float marginRight();

    @VTID(15)
    void marginRight(
        float marginRight);

    @VTID(16)
    float marginTop();

    @VTID(17)
    void marginTop(
        float marginTop);

    @VTID(18)
    mol.office.MsoTextOrientation orientation();

    @VTID(19)
    void orientation(
        mol.office.MsoTextOrientation orientation);

    @VTID(20)
    mol.office.MsoHorizontalAnchor horizontalAnchor();

    @VTID(21)
    void horizontalAnchor(
        mol.office.MsoHorizontalAnchor horizontalAnchor);

    @VTID(22)
    mol.office.MsoVerticalAnchor verticalAnchor();

    @VTID(23)
    void verticalAnchor(
        mol.office.MsoVerticalAnchor verticalAnchor);

    @VTID(24)
    mol.office.MsoPathFormat pathFormat();

    @VTID(25)
    void pathFormat(
        mol.office.MsoPathFormat pathFormat);

    @VTID(26)
    mol.office.MsoWarpFormat warpFormat();

    @VTID(27)
    void warpFormat(
        mol.office.MsoWarpFormat warpFormat);

    @VTID(28)
    mol.office.MsoPresetTextEffect wordArtformat();

    @VTID(29)
    void wordArtformat(
        mol.office.MsoPresetTextEffect wordArtformat);

    @VTID(30)
    mol.office.MsoTriState wordWrap();

    @VTID(31)
    void wordWrap(
        mol.office.MsoTriState wordWrap);

    @VTID(32)
    mol.office.MsoAutoSize autoSize();

    @VTID(33)
    void autoSize(
        mol.office.MsoAutoSize autoSize);

    @VTID(34)
    mol.office.ThreeDFormat threeD();

    @VTID(35)
    mol.office.MsoTriState hasText();

    @VTID(36)
    mol.office.TextRange2 textRange();

    @VTID(37)
    mol.office.TextColumn2 column();

    @VTID(38)
    mol.office.Ruler2 ruler();

    @VTID(39)
    void deleteText();

}
