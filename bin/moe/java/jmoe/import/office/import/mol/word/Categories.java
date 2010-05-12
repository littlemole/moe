package mol.word  ;

import com4j.*;

@IID("{6E47678B-A879-4E56-8698-3B7CF169FAD4}")
public interface Categories extends Com4jObject {
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
    mol.word.Category item(
        java.lang.Object index);

}
