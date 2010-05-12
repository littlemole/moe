package mol.word  ;

import com4j.*;

@IID("{79635BF1-BD1D-4B3F-A520-C1106F1AAAD8}")
public interface Break extends Com4jObject {
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
    int pageIndex();

}
