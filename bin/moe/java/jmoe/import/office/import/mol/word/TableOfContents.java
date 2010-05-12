package mol.word  ;

import com4j.*;

@IID("{00020913-0000-0000-C000-000000000046}")
public interface TableOfContents extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean useHeadingStyles();

    @VTID(11)
    void useHeadingStyles(
        boolean prop);

    @VTID(12)
    boolean useFields();

    @VTID(13)
    void useFields(
        boolean prop);

    @VTID(14)
    int upperHeadingLevel();

    @VTID(15)
    void upperHeadingLevel(
        int prop);

    @VTID(16)
    int lowerHeadingLevel();

    @VTID(17)
    void lowerHeadingLevel(
        int prop);

    @VTID(18)
    java.lang.String tableID();

    @VTID(19)
    void tableID(
        java.lang.String prop);

    @VTID(20)
    mol.word.HeadingStyles headingStyles();

    @VTID(20)
    @ReturnValue(defaultPropertyThrough={mol.word.HeadingStyles.class})
    mol.word.HeadingStyle headingStyles(
        int index);

    @VTID(21)
    boolean rightAlignPageNumbers();

    @VTID(22)
    void rightAlignPageNumbers(
        boolean prop);

    @VTID(23)
    boolean includePageNumbers();

    @VTID(24)
    void includePageNumbers(
        boolean prop);

    @VTID(25)
    mol.word.Range range();

    @VTID(26)
    mol.word.WdTabLeader tabLeader();

    @VTID(27)
    void tabLeader(
        mol.word.WdTabLeader prop);

    @VTID(28)
    void delete();

    @VTID(29)
    void updatePageNumbers();

    @VTID(30)
    void update();

    @VTID(31)
    boolean useHyperlinks();

    @VTID(32)
    void useHyperlinks(
        boolean prop);

    @VTID(33)
    boolean hidePageNumbersInWeb();

    @VTID(34)
    void hidePageNumbersInWeb(
        boolean prop);

}
