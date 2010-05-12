package mol.word  ;

import com4j.*;

@IID("{00020998-0000-0000-C000-000000000046}")
public interface KeyBinding extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String command();

    @VTID(11)
    java.lang.String keyString();

    @VTID(12)
    boolean _protected();

    @VTID(13)
    mol.word.WdKeyCategory keyCategory();

    @VTID(14)
    int keyCode();

    @VTID(15)
    int keyCode2();

    @VTID(16)
    java.lang.String commandParameter();

    @VTID(17)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject context();

    @VTID(18)
    void clear();

    @VTID(19)
    void disable();

    @VTID(20)
    void execute();

    @VTID(21)
    void rebind(
        mol.word.WdKeyCategory keyCategory,
        java.lang.String command,
        java.lang.Object commandParameter);

}
