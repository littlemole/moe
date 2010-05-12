package mol.word  ;

import com4j.*;

@IID("{DB8E3072-E106-4453-8E7C-53056F1D30DC}")
public interface SmartTagTypes extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.SmartTagType item(
        java.lang.Object index);

    @VTID(13)
    void reloadAll();

}
