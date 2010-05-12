package mol.word  ;

import com4j.*;

@IID("{000209B2-0000-0000-C000-000000000046}")
public interface TextFrame extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    mol.word.Shape parent();

    @VTID(10)
    float marginBottom();

    @VTID(11)
    void marginBottom(
        float prop);

    @VTID(12)
    float marginLeft();

    @VTID(13)
    void marginLeft(
        float prop);

    @VTID(14)
    float marginRight();

    @VTID(15)
    void marginRight(
        float prop);

    @VTID(16)
    float marginTop();

    @VTID(17)
    void marginTop(
        float prop);

    @VTID(18)
    mol.office.MsoTextOrientation orientation();

    @VTID(19)
    void orientation(
        mol.office.MsoTextOrientation prop);

    @VTID(20)
    mol.word.Range textRange();

    @VTID(21)
    mol.word.Range containingRange();

    @VTID(22)
    mol.word.TextFrame next();

    @VTID(23)
    void next(
        mol.word.TextFrame prop);

    @VTID(24)
    mol.word.TextFrame previous();

    @VTID(25)
    void previous(
        mol.word.TextFrame prop);

    @VTID(26)
    boolean overflowing();

    @VTID(27)
    int hasText();

    @VTID(28)
    void breakForwardLink();

    @VTID(29)
    boolean validLinkTarget(
        mol.word.TextFrame targetTextFrame);

    @VTID(30)
    int autoSize();

    @VTID(31)
    void autoSize(
        int prop);

    @VTID(32)
    int wordWrap();

    @VTID(33)
    void wordWrap(
        int prop);

    @VTID(34)
    mol.office.MsoVerticalAnchor verticalAnchor();

    @VTID(35)
    void verticalAnchor(
        mol.office.MsoVerticalAnchor prop);

}
