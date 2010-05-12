package mol.word  ;

import com4j.*;

@IID("{0002095A-0000-0000-C000-000000000046}")
public interface Sections extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word.Section first();

    @VTID(10)
    mol.word.Section last();

    @VTID(11)
    mol.word._Application application();

    @VTID(12)
    int creator();

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(14)
    mol.word.PageSetup pageSetup();

    @VTID(15)
    void pageSetup(
        mol.word.PageSetup prop);

    @VTID(16)
    @DefaultMethod
    mol.word.Section item(
        int index);

    @VTID(17)
    mol.word.Section add(
        java.lang.Object range,
        java.lang.Object start);

}
