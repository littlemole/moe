package mol.word  ;

import com4j.*;

@IID("{000209B0-0000-0000-C000-000000000046}")
public interface Find extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean forward();

    @VTID(11)
    void forward(
        boolean prop);

    @VTID(12)
    mol.word._Font font();

    @VTID(13)
    void font(
        mol.word._Font prop);

    @VTID(14)
    boolean found();

    @VTID(15)
    boolean matchAllWordForms();

    @VTID(16)
    void matchAllWordForms(
        boolean prop);

    @VTID(17)
    boolean matchCase();

    @VTID(18)
    void matchCase(
        boolean prop);

    @VTID(19)
    boolean matchWildcards();

    @VTID(20)
    void matchWildcards(
        boolean prop);

    @VTID(21)
    boolean matchSoundsLike();

    @VTID(22)
    void matchSoundsLike(
        boolean prop);

    @VTID(23)
    boolean matchWholeWord();

    @VTID(24)
    void matchWholeWord(
        boolean prop);

    @VTID(25)
    boolean matchFuzzy();

    @VTID(26)
    void matchFuzzy(
        boolean prop);

    @VTID(27)
    boolean matchByte();

    @VTID(28)
    void matchByte(
        boolean prop);

    @VTID(29)
    mol.word._ParagraphFormat paragraphFormat();

    @VTID(30)
    void paragraphFormat(
        mol.word._ParagraphFormat prop);

    @VTID(31)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object style();

    @VTID(32)
    void style(
        java.lang.Object prop);

    @VTID(33)
    java.lang.String text();

    @VTID(34)
    void text(
        java.lang.String prop);

    @VTID(35)
    mol.word.WdLanguageID languageID();

    @VTID(36)
    void languageID(
        mol.word.WdLanguageID prop);

    @VTID(37)
    int highlight();

    @VTID(38)
    void highlight(
        int prop);

    @VTID(39)
    mol.word.Replacement replacement();

    @VTID(40)
    mol.word.Frame frame();

    @VTID(41)
    mol.word.WdFindWrap wrap();

    @VTID(42)
    void wrap(
        mol.word.WdFindWrap prop);

    @VTID(43)
    boolean format();

    @VTID(44)
    void format(
        boolean prop);

    @VTID(45)
    mol.word.WdLanguageID languageIDFarEast();

    @VTID(46)
    void languageIDFarEast(
        mol.word.WdLanguageID prop);

    @VTID(47)
    mol.word.WdLanguageID languageIDOther();

    @VTID(48)
    void languageIDOther(
        mol.word.WdLanguageID prop);

    @VTID(49)
    boolean correctHangulEndings();

    @VTID(50)
    void correctHangulEndings(
        boolean prop);

    @VTID(51)
    boolean executeOld(
        java.lang.Object findText,
        java.lang.Object matchCase,
        java.lang.Object matchWholeWord,
        java.lang.Object matchWildcards,
        java.lang.Object matchSoundsLike,
        java.lang.Object matchAllWordForms,
        java.lang.Object forward,
        java.lang.Object wrap,
        java.lang.Object format,
        java.lang.Object replaceWith,
        java.lang.Object replace);

    @VTID(52)
    void clearFormatting();

    @VTID(53)
    void setAllFuzzyOptions();

    @VTID(54)
    void clearAllFuzzyOptions();

    @VTID(55)
    boolean execute(
        java.lang.Object findText,
        java.lang.Object matchCase,
        java.lang.Object matchWholeWord,
        java.lang.Object matchWildcards,
        java.lang.Object matchSoundsLike,
        java.lang.Object matchAllWordForms,
        java.lang.Object forward,
        java.lang.Object wrap,
        java.lang.Object format,
        java.lang.Object replaceWith,
        java.lang.Object replace,
        java.lang.Object matchKashida,
        java.lang.Object matchDiacritics,
        java.lang.Object matchAlefHamza,
        java.lang.Object matchControl);

    @VTID(56)
    int noProofing();

    @VTID(57)
    void noProofing(
        int prop);

    @VTID(58)
    boolean matchKashida();

    @VTID(59)
    void matchKashida(
        boolean prop);

    @VTID(60)
    boolean matchDiacritics();

    @VTID(61)
    void matchDiacritics(
        boolean prop);

    @VTID(62)
    boolean matchAlefHamza();

    @VTID(63)
    void matchAlefHamza(
        boolean prop);

    @VTID(64)
    boolean matchControl();

    @VTID(65)
    void matchControl(
        boolean prop);

    @VTID(66)
    boolean matchPhrase();

    @VTID(67)
    void matchPhrase(
        boolean prop);

    @VTID(68)
    boolean matchPrefix();

    @VTID(69)
    void matchPrefix(
        boolean prop);

    @VTID(70)
    boolean matchSuffix();

    @VTID(71)
    void matchSuffix(
        boolean prop);

    @VTID(72)
    boolean ignoreSpace();

    @VTID(73)
    void ignoreSpace(
        boolean prop);

    @VTID(74)
    boolean ignorePunct();

    @VTID(75)
    void ignorePunct(
        boolean prop);

    @VTID(76)
    boolean hitHighlight(
        java.lang.Object findText,
        java.lang.Object highlightColor,
        java.lang.Object textColor,
        java.lang.Object matchCase,
        java.lang.Object matchWholeWord,
        java.lang.Object matchPrefix,
        java.lang.Object matchSuffix,
        java.lang.Object matchPhrase,
        java.lang.Object matchWildcards,
        java.lang.Object matchSoundsLike,
        java.lang.Object matchAllWordForms,
        java.lang.Object matchByte,
        java.lang.Object matchFuzzy,
        java.lang.Object matchKashida,
        java.lang.Object matchDiacritics,
        java.lang.Object matchAlefHamza,
        java.lang.Object matchControl,
        java.lang.Object ignoreSpace,
        java.lang.Object ignorePunct,
        java.lang.Object hanjaPhoneticHangul);

    @VTID(77)
    boolean clearHitHighlight();

    @VTID(78)
    boolean execute2007(
        java.lang.Object findText,
        java.lang.Object matchCase,
        java.lang.Object matchWholeWord,
        java.lang.Object matchWildcards,
        java.lang.Object matchSoundsLike,
        java.lang.Object matchAllWordForms,
        java.lang.Object forward,
        java.lang.Object wrap,
        java.lang.Object format,
        java.lang.Object replaceWith,
        java.lang.Object replace,
        java.lang.Object matchKashida,
        java.lang.Object matchDiacritics,
        java.lang.Object matchAlefHamza,
        java.lang.Object matchControl,
        java.lang.Object matchPrefix,
        java.lang.Object matchSuffix,
        java.lang.Object matchPhrase,
        java.lang.Object ignoreSpace,
        java.lang.Object ignorePunct);

    @VTID(79)
    boolean hanjaPhoneticHangul();

    @VTID(80)
    void hanjaPhoneticHangul(
        boolean prop);

}
