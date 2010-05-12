package mol.word  ;

import com4j.*;

@IID("{1B426348-607D-433C-9216-C5D2BF0EF31F}")
public interface OMathMatRows extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.OMathMatRow item(
        int index);

    @VTID(13)
    mol.word.OMathMatRow add(
        java.lang.Object beforeRow);

}
