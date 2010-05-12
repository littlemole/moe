package mol.word  ;

import com4j.*;

@IID("{00020997-0000-0000-C000-000000000046}")
public interface KeysBoundTo extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.WdKeyCategory keyCategory();

    @VTID(13)
    java.lang.String command();

    @VTID(14)
    java.lang.String commandParameter();

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject context();

    @VTID(16)
    @DefaultMethod
    mol.word.KeyBinding item(
        int index);

    @VTID(17)
    mol.word.KeyBinding key(
        int keyCode,
        java.lang.Object keyCode2);

}
