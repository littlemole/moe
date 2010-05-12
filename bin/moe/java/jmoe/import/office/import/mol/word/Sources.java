package mol.word  ;

import com4j.*;

@IID("{FA02A26B-6550-45C5-B6F0-80E757CD3482}")
public interface Sources extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.Source item(
        int index);

    @VTID(13)
    void add(
        java.lang.String data);

}
