package mol.word  ;

import com4j.*;

@IID("{0002097C-0000-0000-C000-000000000046}")
public interface Indexes extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.WdIndexFormat format();

    @VTID(13)
    void format(
        mol.word.WdIndexFormat prop);

    @VTID(14)
    @DefaultMethod
    mol.word.Index item(
        int index);

    @VTID(15)
    mol.word.Index addOld(
        mol.word.Range range,
        java.lang.Object headingSeparator,
        java.lang.Object rightAlignPageNumbers,
        java.lang.Object type,
        java.lang.Object numberOfColumns,
        java.lang.Object accentedLetters);

    @VTID(16)
    mol.word.Field markEntry(
        mol.word.Range range,
        java.lang.Object entry,
        java.lang.Object entryAutoText,
        java.lang.Object crossReference,
        java.lang.Object crossReferenceAutoText,
        java.lang.Object bookmarkName,
        java.lang.Object bold,
        java.lang.Object italic,
        java.lang.Object reading);

    @VTID(17)
    void markAllEntries(
        mol.word.Range range,
        java.lang.Object entry,
        java.lang.Object entryAutoText,
        java.lang.Object crossReference,
        java.lang.Object crossReferenceAutoText,
        java.lang.Object bookmarkName,
        java.lang.Object bold,
        java.lang.Object italic);

    @VTID(18)
    void autoMarkEntries(
        java.lang.String concordanceFileName);

    @VTID(19)
    mol.word.Index add(
        mol.word.Range range,
        java.lang.Object headingSeparator,
        java.lang.Object rightAlignPageNumbers,
        java.lang.Object type,
        java.lang.Object numberOfColumns,
        java.lang.Object accentedLetters,
        java.lang.Object sortBy,
        java.lang.Object indexLanguage);

}
