package mol.word  ;

import com4j.*;

@IID("{4A6AE865-199D-4EA3-9F6B-125BD9C40EDF}")
public interface Source extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String tag();

    @VTID(11)
    java.lang.String field(
        java.lang.String name);

    @VTID(12)
    void field(
        java.lang.String name,
        java.lang.String prop);

    @VTID(13)
    java.lang.String xml();

    @VTID(14)
    boolean cited();

    @VTID(15)
    void delete();

}
