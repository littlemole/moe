package mol.word  ;

import com4j.*;

@IID("{00020929-0000-0000-C000-000000000046}")
public interface FormFields extends Com4jObject,Iterable<Com4jObject> {
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
    boolean shaded();

    @VTID(12)
    void shaded(
        boolean prop);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(14)
    @DefaultMethod
    mol.word.FormField item(
        java.lang.Object index);

    @VTID(15)
    mol.word.FormField add(
        mol.word.Range range,
        mol.word.WdFieldType type);

}
