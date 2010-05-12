package mol.word  ;

import com4j.*;

@IID("{AED7E08C-14F0-4F33-921D-4C5353137BF6}")
public interface Editors extends Com4jObject {
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
    mol.word.Editor item(
        java.lang.Object index);

    @VTID(12)
    mol.word.Editor add(
        java.lang.Object editorID);

}
