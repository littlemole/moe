package mol.word  ;

import com4j.*;

@IID("{0002092C-0000-0000-C000-000000000046}")
public interface Style extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String nameLocal();

    @VTID(11)
    @DefaultMethod
    void nameLocal(
        java.lang.String prop);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object baseStyle();

    @VTID(13)
    void baseStyle(
        java.lang.Object prop);

    @VTID(14)
    java.lang.String description();

    @VTID(15)
    mol.word.WdStyleType type();

    @VTID(16)
    boolean builtIn();

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object nextParagraphStyle();

    @VTID(18)
    void nextParagraphStyle(
        java.lang.Object prop);

    @VTID(19)
    boolean inUse();

    @VTID(20)
    mol.word.Shading shading();

    @VTID(21)
    mol.word.Borders borders();

    @VTID(21)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(22)
    void borders(
        mol.word.Borders prop);

    @VTID(23)
    mol.word._ParagraphFormat paragraphFormat();

    @VTID(24)
    void paragraphFormat(
        mol.word._ParagraphFormat prop);

    @VTID(25)
    mol.word._Font font();

    @VTID(26)
    void font(
        mol.word._Font prop);

    @VTID(27)
    mol.word.Frame frame();

    @VTID(28)
    mol.word.WdLanguageID languageID();

    @VTID(29)
    void languageID(
        mol.word.WdLanguageID prop);

    @VTID(30)
    boolean automaticallyUpdate();

    @VTID(31)
    void automaticallyUpdate(
        boolean prop);

    @VTID(32)
    mol.word.ListTemplate listTemplate();

    @VTID(33)
    int listLevelNumber();

    @VTID(34)
    mol.word.WdLanguageID languageIDFarEast();

    @VTID(35)
    void languageIDFarEast(
        mol.word.WdLanguageID prop);

    @VTID(36)
    boolean hidden();

    @VTID(37)
    void hidden(
        boolean prop);

    @VTID(38)
    void delete();

    @VTID(39)
    void linkToListTemplate(
        mol.word.ListTemplate listTemplate,
        java.lang.Object listLevelNumber);

    @VTID(40)
    int noProofing();

    @VTID(41)
    void noProofing(
        int prop);

    @VTID(42)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object linkStyle();

    @VTID(43)
    void linkStyle(
        java.lang.Object prop);

    @VTID(44)
    boolean visibility();

    @VTID(45)
    void visibility(
        boolean prop);

    @VTID(46)
    boolean noSpaceBetweenParagraphsOfSameStyle();

    @VTID(47)
    void noSpaceBetweenParagraphsOfSameStyle(
        boolean prop);

    @VTID(48)
    mol.word.TableStyle table();

    @VTID(49)
    boolean locked();

    @VTID(50)
    void locked(
        boolean prop);

    @VTID(51)
    int priority();

    @VTID(52)
    void priority(
        int prop);

    @VTID(53)
    boolean unhideWhenUsed();

    @VTID(54)
    void unhideWhenUsed(
        boolean prop);

    @VTID(55)
    boolean quickStyle();

    @VTID(56)
    void quickStyle(
        boolean prop);

    @VTID(57)
    boolean linked();

}
