package mol.word  ;

import com4j.*;

@IID("{D36C1F42-7044-4B9E-9CA3-85919454DB04}")
public interface XMLNodes extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.XMLNode item(
        int index);

    @VTID(13)
    mol.word.XMLNode add(
        java.lang.String name,
        java.lang.String namespace,
        java.lang.Object range);

}
