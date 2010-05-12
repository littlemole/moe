package mol.word  ;

import com4j.*;

@IID("{00020988-0000-0000-C000-000000000046}")
public interface Subdocuments extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    boolean expanded();

    @VTID(13)
    void expanded(
        boolean prop);

    @VTID(14)
    @DefaultMethod
    mol.word.Subdocument item(
        int index);

    @VTID(15)
    mol.word.Subdocument addFromFile(
        java.lang.Object name,
        java.lang.Object confirmConversions,
        java.lang.Object readOnly,
        java.lang.Object passwordDocument,
        java.lang.Object passwordTemplate,
        java.lang.Object revert,
        java.lang.Object writePasswordDocument,
        java.lang.Object writePasswordTemplate);

    @VTID(16)
    mol.word.Subdocument addFromRange(
        mol.word.Range range);

    @VTID(17)
    void merge(
        java.lang.Object firstSubdocument,
        java.lang.Object lastSubdocument);

    @VTID(18)
    void delete();

    @VTID(19)
    void select();

}
