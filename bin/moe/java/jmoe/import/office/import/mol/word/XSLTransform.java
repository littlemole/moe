package mol.word  ;

import com4j.*;

@IID("{E3124493-7D6A-410F-9A48-CC822C033CEC}")
public interface XSLTransform extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String alias(
        boolean allUsers);

    @VTID(11)
    void alias(
        boolean allUsers,
        java.lang.String prop);

    @VTID(12)
    java.lang.String location(
        boolean allUsers);

    @VTID(13)
    void location(
        boolean allUsers,
        java.lang.String prop);

    @VTID(14)
    void delete();

}
