package mol.word  ;

import com4j.*;

@IID("{0002093F-0000-0000-C000-000000000046}")
public interface Footnote extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.Range range();

    @VTID(11)
    mol.word.Range reference();

    @VTID(12)
    int index();

    @VTID(13)
    void delete();

}
