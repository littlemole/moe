package mol.word  ;

import com4j.*;

@IID("{00020955-0000-0000-C000-000000000046}")
public interface TabStops extends Com4jObject,Iterable<Com4jObject> {
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
    @DefaultMethod
    mol.word.TabStop item(
        java.lang.Object index);

    @VTID(13)
    mol.word.TabStop add(
        float position,
        java.lang.Object alignment,
        java.lang.Object leader);

    @VTID(14)
    void clearAll();

    @VTID(15)
    mol.word.TabStop before(
        float position);

    @VTID(16)
    mol.word.TabStop after(
        float position);

}
