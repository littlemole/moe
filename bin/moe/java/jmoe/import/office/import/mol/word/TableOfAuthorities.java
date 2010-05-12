package mol.word  ;

import com4j.*;

@IID("{00020911-0000-0000-C000-000000000046}")
public interface TableOfAuthorities extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean passim();

    @VTID(11)
    void passim(
        boolean prop);

    @VTID(12)
    boolean keepEntryFormatting();

    @VTID(13)
    void keepEntryFormatting(
        boolean prop);

    @VTID(14)
    int category();

    @VTID(15)
    void category(
        int prop);

    @VTID(16)
    java.lang.String bookmark();

    @VTID(17)
    void bookmark(
        java.lang.String prop);

    @VTID(18)
    java.lang.String separator();

    @VTID(19)
    void separator(
        java.lang.String prop);

    @VTID(20)
    java.lang.String includeSequenceName();

    @VTID(21)
    void includeSequenceName(
        java.lang.String prop);

    @VTID(22)
    java.lang.String entrySeparator();

    @VTID(23)
    void entrySeparator(
        java.lang.String prop);

    @VTID(24)
    java.lang.String pageRangeSeparator();

    @VTID(25)
    void pageRangeSeparator(
        java.lang.String prop);

    @VTID(26)
    boolean includeCategoryHeader();

    @VTID(27)
    void includeCategoryHeader(
        boolean prop);

    @VTID(28)
    java.lang.String pageNumberSeparator();

    @VTID(29)
    void pageNumberSeparator(
        java.lang.String prop);

    @VTID(30)
    mol.word.Range range();

    @VTID(31)
    mol.word.WdTabLeader tabLeader();

    @VTID(32)
    void tabLeader(
        mol.word.WdTabLeader prop);

    @VTID(33)
    void delete();

    @VTID(34)
    void update();

}
