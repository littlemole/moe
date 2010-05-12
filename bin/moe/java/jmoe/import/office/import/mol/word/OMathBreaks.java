package mol.word  ;

import com4j.*;

@IID("{E2E0F3A7-204C-40C5-BAA5-290F374FDF5A}")
public interface OMathBreaks extends Com4jObject {
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
    mol.word.OMathBreak item(
        int index);

    @VTID(12)
    mol.word.OMathBreak add(
        mol.word.Range range);

}
