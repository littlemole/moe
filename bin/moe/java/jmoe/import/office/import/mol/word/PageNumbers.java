package mol.word  ;

import com4j.*;

@IID("{00020986-0000-0000-C000-000000000046}")
public interface PageNumbers extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(11)
    int count();

    @VTID(12)
    mol.word.WdPageNumberStyle numberStyle();

    @VTID(13)
    void numberStyle(
        mol.word.WdPageNumberStyle prop);

    @VTID(14)
    boolean includeChapterNumber();

    @VTID(15)
    void includeChapterNumber(
        boolean prop);

    @VTID(16)
    int headingLevelForChapter();

    @VTID(17)
    void headingLevelForChapter(
        int prop);

    @VTID(18)
    mol.word.WdSeparatorType chapterPageSeparator();

    @VTID(19)
    void chapterPageSeparator(
        mol.word.WdSeparatorType prop);

    @VTID(20)
    boolean restartNumberingAtSection();

    @VTID(21)
    void restartNumberingAtSection(
        boolean prop);

    @VTID(22)
    int startingNumber();

    @VTID(23)
    void startingNumber(
        int prop);

    @VTID(24)
    boolean showFirstPageNumber();

    @VTID(25)
    void showFirstPageNumber(
        boolean prop);

    @VTID(26)
    @DefaultMethod
    mol.word.PageNumber item(
        int index);

    @VTID(27)
    mol.word.PageNumber add(
        java.lang.Object pageNumberAlignment,
        java.lang.Object firstPage);

    @VTID(28)
    boolean doubleQuote();

    @VTID(29)
    void doubleQuote(
        boolean prop);

}
