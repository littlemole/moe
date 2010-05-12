package mol.word  ;

import com4j.*;

@IID("{000209DB-0000-0000-C000-000000000046}")
public interface EmailOptions extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean useThemeStyle();

    @VTID(11)
    void useThemeStyle(
        boolean prop);

    @VTID(12)
    java.lang.String markCommentsWith();

    @VTID(13)
    void markCommentsWith(
        java.lang.String prop);

    @VTID(14)
    boolean markComments();

    @VTID(15)
    void markComments(
        boolean prop);

    @VTID(16)
    mol.word.EmailSignature emailSignature();

    @VTID(17)
    mol.word.Style composeStyle();

    @VTID(18)
    mol.word.Style replyStyle();

    @VTID(19)
    java.lang.String themeName();

    @VTID(20)
    void themeName(
        java.lang.String prop);

    @VTID(21)
    boolean dummy1();

    @VTID(22)
    boolean dummy2();

    @VTID(23)
    void dummy3();

    @VTID(24)
    boolean newColorOnReply();

    @VTID(25)
    void newColorOnReply(
        boolean prop);

    @VTID(26)
    mol.word.Style plainTextStyle();

    @VTID(27)
    boolean useThemeStyleOnReply();

    @VTID(28)
    void useThemeStyleOnReply(
        boolean prop);

    @VTID(29)
    boolean autoFormatAsYouTypeApplyHeadings();

    @VTID(30)
    void autoFormatAsYouTypeApplyHeadings(
        boolean prop);

    @VTID(31)
    boolean autoFormatAsYouTypeApplyBorders();

    @VTID(32)
    void autoFormatAsYouTypeApplyBorders(
        boolean prop);

    @VTID(33)
    boolean autoFormatAsYouTypeApplyBulletedLists();

    @VTID(34)
    void autoFormatAsYouTypeApplyBulletedLists(
        boolean prop);

    @VTID(35)
    boolean autoFormatAsYouTypeApplyNumberedLists();

    @VTID(36)
    void autoFormatAsYouTypeApplyNumberedLists(
        boolean prop);

    @VTID(37)
    boolean autoFormatAsYouTypeReplaceQuotes();

    @VTID(38)
    void autoFormatAsYouTypeReplaceQuotes(
        boolean prop);

    @VTID(39)
    boolean autoFormatAsYouTypeReplaceSymbols();

    @VTID(40)
    void autoFormatAsYouTypeReplaceSymbols(
        boolean prop);

    @VTID(41)
    boolean autoFormatAsYouTypeReplaceOrdinals();

    @VTID(42)
    void autoFormatAsYouTypeReplaceOrdinals(
        boolean prop);

    @VTID(43)
    boolean autoFormatAsYouTypeReplaceFractions();

    @VTID(44)
    void autoFormatAsYouTypeReplaceFractions(
        boolean prop);

    @VTID(45)
    boolean autoFormatAsYouTypeReplacePlainTextEmphasis();

    @VTID(46)
    void autoFormatAsYouTypeReplacePlainTextEmphasis(
        boolean prop);

    @VTID(47)
    boolean autoFormatAsYouTypeFormatListItemBeginning();

    @VTID(48)
    void autoFormatAsYouTypeFormatListItemBeginning(
        boolean prop);

    @VTID(49)
    boolean autoFormatAsYouTypeDefineStyles();

    @VTID(50)
    void autoFormatAsYouTypeDefineStyles(
        boolean prop);

    @VTID(51)
    boolean autoFormatAsYouTypeReplaceHyperlinks();

    @VTID(52)
    void autoFormatAsYouTypeReplaceHyperlinks(
        boolean prop);

    @VTID(53)
    boolean autoFormatAsYouTypeApplyTables();

    @VTID(54)
    void autoFormatAsYouTypeApplyTables(
        boolean prop);

    @VTID(55)
    boolean autoFormatAsYouTypeApplyFirstIndents();

    @VTID(56)
    void autoFormatAsYouTypeApplyFirstIndents(
        boolean prop);

    @VTID(57)
    boolean autoFormatAsYouTypeApplyDates();

    @VTID(58)
    void autoFormatAsYouTypeApplyDates(
        boolean prop);

    @VTID(59)
    boolean autoFormatAsYouTypeApplyClosings();

    @VTID(60)
    void autoFormatAsYouTypeApplyClosings(
        boolean prop);

    @VTID(61)
    boolean autoFormatAsYouTypeMatchParentheses();

    @VTID(62)
    void autoFormatAsYouTypeMatchParentheses(
        boolean prop);

    @VTID(63)
    boolean autoFormatAsYouTypeReplaceFarEastDashes();

    @VTID(64)
    void autoFormatAsYouTypeReplaceFarEastDashes(
        boolean prop);

    @VTID(65)
    boolean autoFormatAsYouTypeDeleteAutoSpaces();

    @VTID(66)
    void autoFormatAsYouTypeDeleteAutoSpaces(
        boolean prop);

    @VTID(67)
    boolean autoFormatAsYouTypeInsertClosings();

    @VTID(68)
    void autoFormatAsYouTypeInsertClosings(
        boolean prop);

    @VTID(69)
    boolean autoFormatAsYouTypeAutoLetterWizard();

    @VTID(70)
    void autoFormatAsYouTypeAutoLetterWizard(
        boolean prop);

    @VTID(71)
    boolean autoFormatAsYouTypeInsertOvers();

    @VTID(72)
    void autoFormatAsYouTypeInsertOvers(
        boolean prop);

    @VTID(73)
    boolean relyOnCSS();

    @VTID(74)
    void relyOnCSS(
        boolean prop);

    @VTID(75)
    mol.word.WdEmailHTMLFidelity htmlFidelity();

    @VTID(76)
    void htmlFidelity(
        mol.word.WdEmailHTMLFidelity prop);

    @VTID(77)
    boolean embedSmartTag();

    @VTID(78)
    void embedSmartTag(
        boolean prop);

    @VTID(79)
    boolean tabIndentKey();

    @VTID(80)
    void tabIndentKey(
        boolean prop);

}
