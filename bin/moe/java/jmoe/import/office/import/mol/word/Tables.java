package mol.word  ;

import com4j.*;

@IID("{0002094D-0000-0000-C000-000000000046}")
public interface Tables extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word._Application application();

    @VTID(10)
    int creator();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    @DefaultMethod
    mol.word.Table item(
        int index);

    @VTID(13)
    mol.word.Table addOld(
        mol.word.Range range,
        int numRows,
        int numColumns);

    @VTID(14)
    mol.word.Table add(
        mol.word.Range range,
        int numRows,
        int numColumns,
        java.lang.Object defaultTableBehavior,
        java.lang.Object autoFitBehavior);

    @VTID(15)
    int nestingLevel();

}
