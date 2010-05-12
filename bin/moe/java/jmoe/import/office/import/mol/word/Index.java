package mol.word  ;

import com4j.*;

@IID("{0002097D-0000-0000-C000-000000000046}")
public interface Index extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdHeadingSeparator headingSeparator();

    @VTID(11)
    void headingSeparator(
        mol.word.WdHeadingSeparator prop);

    @VTID(12)
    boolean rightAlignPageNumbers();

    @VTID(13)
    void rightAlignPageNumbers(
        boolean prop);

    @VTID(14)
    mol.word.WdIndexType type();

    @VTID(15)
    void type(
        mol.word.WdIndexType prop);

    @VTID(16)
    int numberOfColumns();

    @VTID(17)
    void numberOfColumns(
        int prop);

    @VTID(18)
    mol.word.Range range();

    @VTID(19)
    mol.word.WdTabLeader tabLeader();

    @VTID(20)
    void tabLeader(
        mol.word.WdTabLeader prop);

    @VTID(21)
    boolean accentedLetters();

    @VTID(22)
    void accentedLetters(
        boolean prop);

    @VTID(23)
    mol.word.WdIndexSortBy sortBy();

    @VTID(24)
    void sortBy(
        mol.word.WdIndexSortBy prop);

    @VTID(25)
    mol.word.WdIndexFilter filter();

    @VTID(26)
    void filter(
        mol.word.WdIndexFilter prop);

    @VTID(27)
    void delete();

    @VTID(28)
    void update();

    @VTID(29)
    mol.word.WdLanguageID indexLanguage();

    @VTID(30)
    void indexLanguage(
        mol.word.WdLanguageID prop);

}
