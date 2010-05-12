package mol.word  ;

import com4j.*;

@IID("{497142A4-16FD-42C6-BC58-15D89345FC21}")
public interface OMathFunctions extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    int count();

    @VTID(12)
    @DefaultMethod
    mol.word.OMathFunction item(
        int index);

    @VTID(13)
    mol.word.OMathFunction add(
        mol.word.Range range,
        mol.word.WdOMathFunctionType type,
        java.lang.Object numArgs,
        java.lang.Object numCols);

}
