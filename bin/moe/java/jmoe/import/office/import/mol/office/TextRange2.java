package mol.office  ;

import com4j.*;

@IID("{000C0397-0000-0000-C000-000000000046}")
public interface TextRange2 extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    java.lang.String text();

    @VTID(10)
    @DefaultMethod
    void text(
        java.lang.String pbstrText);

    @VTID(11)
    int count();

    @VTID(12)
    mol.office.TextRange2 item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(15)
    mol.office.TextRange2 paragraphs(
        int start,
        int length);

    @VTID(16)
    mol.office.TextRange2 sentences(
        int start,
        int length);

    @VTID(17)
    mol.office.TextRange2 words(
        int start,
        int length);

    @VTID(18)
    mol.office.TextRange2 characters(
        int start,
        int length);

    @VTID(19)
    mol.office.TextRange2 lines(
        int start,
        int length);

    @VTID(20)
    mol.office.TextRange2 runs(
        int start,
        int length);

    @VTID(21)
    mol.office.ParagraphFormat2 paragraphFormat();

    @VTID(22)
    mol.office.Font2 font();

    @VTID(23)
    int length();

    @VTID(24)
    int start();

    @VTID(25)
    float boundLeft();

    @VTID(26)
    float boundTop();

    @VTID(27)
    float boundWidth();

    @VTID(28)
    float boundHeight();

    @VTID(29)
    mol.office.TextRange2 trimText();

    @VTID(30)
    mol.office.TextRange2 insertAfter(
        java.lang.String newText);

    @VTID(31)
    mol.office.TextRange2 insertBefore(
        java.lang.String newText);

    @VTID(32)
    mol.office.TextRange2 insertSymbol(
        java.lang.String fontName,
        int charNumber,
        mol.office.MsoTriState unicode);

    @VTID(33)
    void select();

    @VTID(34)
    void cut();

    @VTID(35)
    void copy();

    @VTID(36)
    void delete();

    @VTID(37)
    mol.office.TextRange2 paste();

    @VTID(38)
    mol.office.TextRange2 pasteSpecial(
        mol.office.MsoClipboardFormat format);

    @VTID(39)
    void changeCase(
        mol.office.MsoTextChangeCase type);

    @VTID(40)
    void addPeriods();

    @VTID(41)
    void removePeriods();

    @VTID(42)
    mol.office.TextRange2 find(
        java.lang.String findWhat,
        int after,
        mol.office.MsoTriState matchCase,
        mol.office.MsoTriState wholeWords);

    @VTID(43)
    mol.office.TextRange2 replace(
        java.lang.String findWhat,
        java.lang.String replaceWhat,
        int after,
        mol.office.MsoTriState matchCase,
        mol.office.MsoTriState wholeWords);

    @VTID(44)
    void rotatedBounds(
        Holder<Float> x1,
        Holder<Float> y1,
        Holder<Float> x2,
        Holder<Float> y2,
        Holder<Float> x3,
        Holder<Float> y3,
        Holder<Float> x4,
        Holder<Float> y4);

    @VTID(45)
    mol.office.MsoLanguageID languageID();

    @VTID(46)
    void languageID(
        mol.office.MsoLanguageID languageID);

    @VTID(47)
    void rtlRun();

    @VTID(48)
    void ltrRun();

}
