package mol.word  ;

import com4j.*;

@IID("{000209B8-0000-0000-C000-000000000046}")
public interface Dialog extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdWordDialogTab defaultTab();

    @VTID(11)
    void defaultTab(
        mol.word.WdWordDialogTab prop);

    @VTID(12)
    @DefaultMethod
    mol.word.WdWordDialog type();

    @VTID(13)
    int show(
        java.lang.Object timeOut);

    @VTID(14)
    int display(
        java.lang.Object timeOut);

    @VTID(15)
    void execute();

    @VTID(16)
    void update();

    @VTID(17)
    java.lang.String commandName();

    @VTID(18)
    int commandBarId();

}
