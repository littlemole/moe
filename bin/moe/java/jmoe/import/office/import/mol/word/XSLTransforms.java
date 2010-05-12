package mol.word  ;

import com4j.*;

@IID("{C774F5EA-A539-4284-A1BE-30AEC052D899}")
public interface XSLTransforms extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.XSLTransform item(
        java.lang.Object index);

    @VTID(13)
    mol.word.XSLTransform add(
        java.lang.String location,
        java.lang.Object alias,
        boolean installForAllUsers);

}
