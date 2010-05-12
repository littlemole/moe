package mol.word  ;

import com4j.*;

@IID("{18CD5EC8-8B7B-42C8-992A-2A407468642C}")
public interface OMathAutoCorrectEntries extends Com4jObject,Iterable<Com4jObject> {
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
    @DefaultMethod
    mol.word.OMathAutoCorrectEntry item(
        java.lang.Object index);

    @VTID(13)
    mol.word.OMathAutoCorrectEntry add(
        java.lang.String name,
        java.lang.String value);

}
