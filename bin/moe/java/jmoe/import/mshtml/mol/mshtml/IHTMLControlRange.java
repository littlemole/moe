package mol.mshtml  ;

import com4j.*;

@IID("{3050F29C-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLControlRange extends Com4jObject {
    @VTID(7)
    void select();

    @VTID(8)
    void add(
        mol.mshtml.IHTMLControlElement item);

    @VTID(9)
    void remove(
        int index);

    @VTID(10)
    @DefaultMethod
    mol.mshtml.IHTMLElement item(
        int index);

    @VTID(11)
    void scrollIntoView(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varargStart);

    @VTID(12)
    boolean queryCommandSupported(
        java.lang.String cmdID);

    @VTID(13)
    boolean queryCommandEnabled(
        java.lang.String cmdID);

    @VTID(14)
    boolean queryCommandState(
        java.lang.String cmdID);

    @VTID(15)
    boolean queryCommandIndeterm(
        java.lang.String cmdID);

    @VTID(16)
    java.lang.String queryCommandText(
        java.lang.String cmdID);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object queryCommandValue(
        java.lang.String cmdID);

    @VTID(18)
    boolean execCommand(
        java.lang.String cmdID,
        boolean showUI,
        @MarshalAs(NativeType.VARIANT) java.lang.Object value);

    @VTID(19)
    boolean execCommandShowHelp(
        java.lang.String cmdID);

    @VTID(20)
    mol.mshtml.IHTMLElement commonParentElement();

    @VTID(21)
    int length();

}
