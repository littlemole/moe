package mol.word  ;

import com4j.*;

@IID("{DD947D72-F33C-4198-9BDF-F86181D05E41}")
public interface Editor extends Com4jObject {
    @VTID(7)
    java.lang.String id();

    @VTID(8)
    java.lang.String name();

    @VTID(9)
    mol.word.Range range();

    @VTID(10)
    mol.word.Range nextRange();

    @VTID(11)
    mol.word._Application application();

    @VTID(12)
    int creator();

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(14)
    void delete();

    @VTID(15)
    void deleteAll();

    @VTID(16)
    void selectAll();

}
