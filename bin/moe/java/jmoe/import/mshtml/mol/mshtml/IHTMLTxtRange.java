package mol.mshtml  ;

import com4j.*;

@IID("{3050F220-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLTxtRange extends Com4jObject {
    @VTID(7)
    java.lang.String htmlText();

    @VTID(8)
    void text(
        java.lang.String p);

    @VTID(9)
    java.lang.String text();

    @VTID(10)
    mol.mshtml.IHTMLElement parentElement();

    @VTID(11)
    mol.mshtml.IHTMLTxtRange duplicate();

    @VTID(12)
    boolean inRange(
        mol.mshtml.IHTMLTxtRange range);

    @VTID(13)
    boolean isEqual(
        mol.mshtml.IHTMLTxtRange range);

    @VTID(14)
    void scrollIntoView(
        boolean fStart);

    @VTID(15)
    void collapse(
        boolean start);

    @VTID(16)
    boolean expand(
        java.lang.String unit);

    @VTID(17)
    int move(
        java.lang.String unit,
        int count);

    @VTID(18)
    int moveStart(
        java.lang.String unit,
        int count);

    @VTID(19)
    int moveEnd(
        java.lang.String unit,
        int count);

    @VTID(20)
    void select();

    @VTID(21)
    void pasteHTML(
        java.lang.String html);

    @VTID(22)
    void moveToElementText(
        mol.mshtml.IHTMLElement element);

    @VTID(23)
    void setEndPoint(
        java.lang.String how,
        mol.mshtml.IHTMLTxtRange sourceRange);

    @VTID(24)
    int compareEndPoints(
        java.lang.String how,
        mol.mshtml.IHTMLTxtRange sourceRange);

    @VTID(25)
    boolean findText(
        java.lang.String string,
        int count,
        int flags);

    @VTID(26)
    void moveToPoint(
        int x,
        int y);

    @VTID(27)
    java.lang.String getBookmark();

    @VTID(28)
    boolean moveToBookmark(
        java.lang.String bookmark);

    @VTID(29)
    boolean queryCommandSupported(
        java.lang.String cmdID);

    @VTID(30)
    boolean queryCommandEnabled(
        java.lang.String cmdID);

    @VTID(31)
    boolean queryCommandState(
        java.lang.String cmdID);

    @VTID(32)
    boolean queryCommandIndeterm(
        java.lang.String cmdID);

    @VTID(33)
    java.lang.String queryCommandText(
        java.lang.String cmdID);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object queryCommandValue(
        java.lang.String cmdID);

    @VTID(35)
    boolean execCommand(
        java.lang.String cmdID,
        boolean showUI,
        @MarshalAs(NativeType.VARIANT) java.lang.Object value);

    @VTID(36)
    boolean execCommandShowHelp(
        java.lang.String cmdID);

}
