package mol.word  ;

import com4j.*;

@IID("{8245795B-9AED-4943-A16D-E586ED8180D1}")
public interface OMathArgs extends Com4jObject {
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
    @DefaultMethod
    mol.word.OMath item(
        int index);

    @VTID(12)
    mol.word.OMath add(
        java.lang.Object beforeArg);

}
