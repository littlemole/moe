package mol.word  ;

import com4j.*;

@IID("{44FEE887-6600-41AB-95A5-DE33C605116C}")
public interface OMathRecognizedFunctions extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(11)
    int count();

    @VTID(12)
    @DefaultMethod
    mol.word.OMathRecognizedFunction item(
        java.lang.Object index);

    @VTID(13)
    mol.word.OMathRecognizedFunction add(
        java.lang.String name);

}
