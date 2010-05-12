package mol.word  ;

import com4j.*;

@IID("{0002092A-0000-0000-C000-000000000046}")
public interface Frame extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdFrameSizeRule heightRule();

    @VTID(11)
    void heightRule(
        mol.word.WdFrameSizeRule prop);

    @VTID(12)
    mol.word.WdFrameSizeRule widthRule();

    @VTID(13)
    void widthRule(
        mol.word.WdFrameSizeRule prop);

    @VTID(14)
    float horizontalDistanceFromText();

    @VTID(15)
    void horizontalDistanceFromText(
        float prop);

    @VTID(16)
    float height();

    @VTID(17)
    void height(
        float prop);

    @VTID(18)
    float horizontalPosition();

    @VTID(19)
    void horizontalPosition(
        float prop);

    @VTID(20)
    boolean lockAnchor();

    @VTID(21)
    void lockAnchor(
        boolean prop);

    @VTID(22)
    mol.word.WdRelativeHorizontalPosition relativeHorizontalPosition();

    @VTID(23)
    void relativeHorizontalPosition(
        mol.word.WdRelativeHorizontalPosition prop);

    @VTID(24)
    mol.word.WdRelativeVerticalPosition relativeVerticalPosition();

    @VTID(25)
    void relativeVerticalPosition(
        mol.word.WdRelativeVerticalPosition prop);

    @VTID(26)
    float verticalDistanceFromText();

    @VTID(27)
    void verticalDistanceFromText(
        float prop);

    @VTID(28)
    float verticalPosition();

    @VTID(29)
    void verticalPosition(
        float prop);

    @VTID(30)
    float width();

    @VTID(31)
    void width(
        float prop);

    @VTID(32)
    boolean textWrap();

    @VTID(33)
    void textWrap(
        boolean prop);

    @VTID(34)
    mol.word.Shading shading();

    @VTID(35)
    mol.word.Borders borders();

    @VTID(35)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(36)
    void borders(
        mol.word.Borders prop);

    @VTID(37)
    mol.word.Range range();

    @VTID(38)
    void delete();

    @VTID(39)
    void select();

    @VTID(40)
    void copy();

    @VTID(41)
    void cut();

}
