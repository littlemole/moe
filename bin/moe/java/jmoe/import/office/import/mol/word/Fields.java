package mol.word  ;

import com4j.*;

@IID("{00020930-0000-0000-C000-000000000046}")
public interface Fields extends Com4jObject,Iterable<Com4jObject> {
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
    int locked();

    @VTID(12)
    void locked(
        int prop);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(14)
    @DefaultMethod
    mol.word.Field item(
        int index);

    @VTID(15)
    void toggleShowCodes();

    @VTID(16)
    int update();

    @VTID(17)
    void unlink();

    @VTID(18)
    void updateSource();

    @VTID(19)
    mol.word.Field add(
        mol.word.Range range,
        java.lang.Object type,
        java.lang.Object text,
        java.lang.Object preserveFormatting);

}
