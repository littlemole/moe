package mol.word  ;

import com4j.*;

@IID("{000209A8-0000-0000-C000-000000000046}")
public interface InlineShape extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.Borders borders();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(11)
    void borders(
        mol.word.Borders prop);

    @VTID(12)
    mol.word.Range range();

    @VTID(13)
    mol.word.LinkFormat linkFormat();

    @VTID(14)
    mol.word.Field field();

    @VTID(15)
    mol.word.OLEFormat oleFormat();

    @VTID(16)
    mol.word.WdInlineShapeType type();

    @VTID(17)
    mol.word.Hyperlink hyperlink();

    @VTID(18)
    float height();

    @VTID(19)
    void height(
        float prop);

    @VTID(20)
    float width();

    @VTID(21)
    void width(
        float prop);

    @VTID(22)
    float scaleHeight();

    @VTID(23)
    void scaleHeight(
        float prop);

    @VTID(24)
    float scaleWidth();

    @VTID(25)
    void scaleWidth(
        float prop);

    @VTID(26)
    mol.office.MsoTriState lockAspectRatio();

    @VTID(27)
    void lockAspectRatio(
        mol.office.MsoTriState prop);

    @VTID(28)
    mol.word.LineFormat line();

    @VTID(29)
    mol.word.FillFormat fill();

    @VTID(30)
    mol.word.PictureFormat pictureFormat();

    @VTID(31)
    void pictureFormat(
        mol.word.PictureFormat prop);

    @VTID(32)
    void activate();

    @VTID(33)
    void reset();

    @VTID(34)
    void delete();

    @VTID(35)
    void select();

    @VTID(36)
    mol.word.Shape convertToShape();

    @VTID(37)
    mol.word.HorizontalLineFormat horizontalLineFormat();

    @VTID(38)
    mol.office.Script script();

    @VTID(39)
    int owsAnchor();

    @VTID(40)
    mol.word.TextEffectFormat textEffect();

    @VTID(41)
    void textEffect(
        mol.word.TextEffectFormat prop);

    @VTID(42)
    java.lang.String alternativeText();

    @VTID(43)
    void alternativeText(
        java.lang.String prop);

    @VTID(44)
    boolean isPictureBullet();

    @VTID(45)
    mol.word.GroupShapes groupItems();

    @VTID(45)
    @ReturnValue(defaultPropertyThrough={mol.word.GroupShapes.class})
    mol.word.Shape groupItems(
        java.lang.Object index);

    @VTID(46)
    mol.office.MsoTriState hasChart();

    @VTID(47)
    boolean dummy1();

    @VTID(48)
    mol.word.SoftEdgeFormat softEdge();

    @VTID(49)
    mol.word.GlowFormat glow();

    @VTID(50)
    mol.word.ReflectionFormat reflection();

    @VTID(51)
    mol.word.ShadowFormat shadow();

}
