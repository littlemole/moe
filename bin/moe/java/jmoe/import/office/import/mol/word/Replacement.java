package mol.word  ;

import com4j.*;

@IID("{000209B1-0000-0000-C000-000000000046}")
public interface Replacement extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word._Font font();

    @VTID(11)
    void font(
        mol.word._Font prop);

    @VTID(12)
    mol.word._ParagraphFormat paragraphFormat();

    @VTID(13)
    void paragraphFormat(
        mol.word._ParagraphFormat prop);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object style();

    @VTID(15)
    void style(
        java.lang.Object prop);

    @VTID(16)
    java.lang.String text();

    @VTID(17)
    void text(
        java.lang.String prop);

    @VTID(18)
    mol.word.WdLanguageID languageID();

    @VTID(19)
    void languageID(
        mol.word.WdLanguageID prop);

    @VTID(20)
    int highlight();

    @VTID(21)
    void highlight(
        int prop);

    @VTID(22)
    mol.word.Frame frame();

    @VTID(23)
    mol.word.WdLanguageID languageIDFarEast();

    @VTID(24)
    void languageIDFarEast(
        mol.word.WdLanguageID prop);

    @VTID(25)
    void clearFormatting();

    @VTID(26)
    int noProofing();

    @VTID(27)
    void noProofing(
        int prop);

}
