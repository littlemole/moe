package mol.word  ;

import com4j.*;

@IID("{EFC71F9C-7F42-4CD4-A7A7-970D7A48CD27}")
public interface OMathMatCols extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.OMathMatCol item(
        int index);

    @VTID(13)
    mol.word.OMathMatCol add(
        java.lang.Object beforeCol);

}
