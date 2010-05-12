package mol.word  ;

import com4j.*;

@IID("{00020996-0000-0000-C000-000000000046}")
public interface KeyBindings extends Com4jObject,Iterable<Com4jObject> {
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
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject context();

    @VTID(13)
    @DefaultMethod
    mol.word.KeyBinding item(
        int index);

    @VTID(14)
    mol.word.KeyBinding add(
        mol.word.WdKeyCategory keyCategory,
        java.lang.String command,
        int keyCode,
        java.lang.Object keyCode2,
        java.lang.Object commandParameter);

    @VTID(15)
    void clearAll();

    @VTID(16)
    mol.word.KeyBinding key(
        int keyCode,
        java.lang.Object keyCode2);

}
