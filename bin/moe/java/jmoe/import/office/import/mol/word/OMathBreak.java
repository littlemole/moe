package mol.word  ;

import com4j.*;

@IID("{65E515D5-F50B-4951-8F38-FA6AC8707387}")
public interface OMathBreak extends Com4jObject {
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
    int alignAt();

    @VTID(12)
    void alignAt(
        int prop);

    @VTID(13)
    void delete();

}
