package mol.word  ;

import com4j.*;

@IID("{00020940-0000-0000-C000-000000000046}")
public interface Comments extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word._Application application();

    @VTID(10)
    int creator();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    java.lang.String showBy();

    @VTID(13)
    void showBy(
        java.lang.String prop);

    @VTID(14)
    @DefaultMethod
    mol.word.Comment item(
        int index);

    @VTID(15)
    mol.word.Comment add(
        mol.word.Range range,
        java.lang.Object text);

}