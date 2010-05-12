package mol.word  ;

import com4j.*;

@IID("{00020989-0000-0000-C000-000000000046}")
public interface Subdocument extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean locked();

    @VTID(11)
    void locked(
        boolean prop);

    @VTID(12)
    mol.word.Range range();

    @VTID(13)
    java.lang.String name();

    @VTID(14)
    java.lang.String path();

    @VTID(15)
    boolean hasFile();

    @VTID(16)
    int level();

    @VTID(17)
    void delete();

    @VTID(18)
    void split(
        mol.word.Range range);

    @VTID(19)
    mol.word._Document open();

}
