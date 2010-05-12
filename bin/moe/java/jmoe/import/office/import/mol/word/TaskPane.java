package mol.word  ;

import com4j.*;

@IID("{B9F1A4E2-0D0A-43B7-8495-139E7ACBD840}")
public interface TaskPane extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean visible();

    @VTID(11)
    void visible(
        boolean prop);

}
