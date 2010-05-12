package mol.word  ;

import com4j.*;

@IID("{00020928-0000-0000-C000-000000000046}")
public interface FormField extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    mol.word.WdFieldType type();

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    void name(
        java.lang.String prop);

    @VTID(13)
    java.lang.String entryMacro();

    @VTID(14)
    void entryMacro(
        java.lang.String prop);

    @VTID(15)
    java.lang.String exitMacro();

    @VTID(16)
    void exitMacro(
        java.lang.String prop);

    @VTID(17)
    boolean ownHelp();

    @VTID(18)
    void ownHelp(
        boolean prop);

    @VTID(19)
    boolean ownStatus();

    @VTID(20)
    void ownStatus(
        boolean prop);

    @VTID(21)
    java.lang.String helpText();

    @VTID(22)
    void helpText(
        java.lang.String prop);

    @VTID(23)
    java.lang.String statusText();

    @VTID(24)
    void statusText(
        java.lang.String prop);

    @VTID(25)
    boolean enabled();

    @VTID(26)
    void enabled(
        boolean prop);

    @VTID(27)
    java.lang.String result();

    @VTID(28)
    void result(
        java.lang.String prop);

    @VTID(29)
    mol.word.TextInput textInput();

    @VTID(30)
    mol.word.CheckBox checkBox();

    @VTID(31)
    mol.word.DropDown dropDown();

    @VTID(32)
    mol.word.FormField next();

    @VTID(33)
    mol.word.FormField previous();

    @VTID(34)
    boolean calculateOnExit();

    @VTID(35)
    void calculateOnExit(
        boolean prop);

    @VTID(36)
    mol.word.Range range();

    @VTID(37)
    void select();

    @VTID(38)
    void copy();

    @VTID(39)
    void cut();

    @VTID(40)
    void delete();

}
