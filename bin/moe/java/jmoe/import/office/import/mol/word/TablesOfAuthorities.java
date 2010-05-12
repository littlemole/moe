package mol.word  ;

import com4j.*;

@IID("{00020912-0000-0000-C000-000000000046}")
public interface TablesOfAuthorities extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.WdToaFormat format();

    @VTID(13)
    void format(
        mol.word.WdToaFormat prop);

    @VTID(14)
    @DefaultMethod
    mol.word.TableOfAuthorities item(
        int index);

    @VTID(15)
    mol.word.TableOfAuthorities add(
        mol.word.Range range,
        java.lang.Object category,
        java.lang.Object bookmark,
        java.lang.Object passim,
        java.lang.Object keepEntryFormatting,
        java.lang.Object separator,
        java.lang.Object includeSequenceName,
        java.lang.Object entrySeparator,
        java.lang.Object pageRangeSeparator,
        java.lang.Object includeCategoryHeader,
        java.lang.Object pageNumberSeparator);

    @VTID(16)
    void nextCitation(
        java.lang.String shortCitation);

    @VTID(17)
    mol.word.Field markCitation(
        mol.word.Range range,
        java.lang.String shortCitation,
        java.lang.Object longCitation,
        java.lang.Object longCitationAutoText,
        java.lang.Object category);

    @VTID(18)
    void markAllCitations(
        java.lang.String shortCitation,
        java.lang.Object longCitation,
        java.lang.Object longCitationAutoText,
        java.lang.Object category);

}
