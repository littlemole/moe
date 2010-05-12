package mol.word  ;

import com4j.*;

@IID("{00020921-0000-0000-C000-000000000046}")
public interface TableOfFigures extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String caption();

    @VTID(11)
    void caption(
        java.lang.String prop);

    @VTID(12)
    boolean includeLabel();

    @VTID(13)
    void includeLabel(
        boolean prop);

    @VTID(14)
    boolean rightAlignPageNumbers();

    @VTID(15)
    void rightAlignPageNumbers(
        boolean prop);

    @VTID(16)
    boolean useHeadingStyles();

    @VTID(17)
    void useHeadingStyles(
        boolean prop);

    @VTID(18)
    int lowerHeadingLevel();

    @VTID(19)
    void lowerHeadingLevel(
        int prop);

    @VTID(20)
    int upperHeadingLevel();

    @VTID(21)
    void upperHeadingLevel(
        int prop);

    @VTID(22)
    boolean includePageNumbers();

    @VTID(23)
    void includePageNumbers(
        boolean prop);

    @VTID(24)
    mol.word.Range range();

    @VTID(25)
    boolean useFields();

    @VTID(26)
    void useFields(
        boolean prop);

    @VTID(27)
    java.lang.String tableID();

    @VTID(28)
    void tableID(
        java.lang.String prop);

    @VTID(29)
    mol.word.HeadingStyles headingStyles();

    @VTID(29)
    @ReturnValue(defaultPropertyThrough={mol.word.HeadingStyles.class})
    mol.word.HeadingStyle headingStyles(
        int index);

    @VTID(30)
    mol.word.WdTabLeader tabLeader();

    @VTID(31)
    void tabLeader(
        mol.word.WdTabLeader prop);

    @VTID(32)
    void delete();

    @VTID(33)
    void updatePageNumbers();

    @VTID(34)
    void update();

    @VTID(35)
    boolean useHyperlinks();

    @VTID(36)
    void useHyperlinks(
        boolean prop);

    @VTID(37)
    boolean hidePageNumbersInWeb();

    @VTID(38)
    void hidePageNumbersInWeb(
        boolean prop);

}
