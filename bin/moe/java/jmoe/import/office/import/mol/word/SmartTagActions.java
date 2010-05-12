package mol.word  ;

import com4j.*;

@IID("{CDE12CD8-767B-4757-8A31-13029A086305}")
public interface SmartTagActions extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.SmartTagAction item(
        java.lang.Object index);

    @VTID(13)
    void reloadActions();

}
