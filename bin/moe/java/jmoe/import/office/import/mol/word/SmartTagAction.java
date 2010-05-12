package mol.word  ;

import com4j.*;

@IID("{DFB6AA6C-1068-420F-969D-01280FCC1630}")
public interface SmartTagAction extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String name();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    void execute();

    @VTID(12)
    mol.word.WdSmartTagControlType type();

    @VTID(13)
    boolean presentInPane();

    @VTID(14)
    boolean expandHelp();

    @VTID(15)
    void expandHelp(
        boolean prop);

    @VTID(16)
    boolean checkboxState();

    @VTID(17)
    void checkboxState(
        boolean prop);

    @VTID(18)
    java.lang.String textboxText();

    @VTID(19)
    void textboxText(
        java.lang.String prop);

    @VTID(20)
    int listSelection();

    @VTID(21)
    void listSelection(
        int prop);

    @VTID(22)
    int radioGroupSelection();

    @VTID(23)
    void radioGroupSelection(
        int prop);

    @VTID(24)
    boolean expandDocumentFragment();

    @VTID(25)
    void expandDocumentFragment(
        boolean prop);

    @VTID(26)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject activeXControl();

}
