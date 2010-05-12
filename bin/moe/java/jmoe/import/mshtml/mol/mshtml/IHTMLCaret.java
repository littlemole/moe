package mol.mshtml  ;

import com4j.*;

@IID("{3050F604-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLCaret extends Com4jObject {
    @VTID(3)
    void moveCaretToPointer(
        mol.mshtml.IDisplayPointer pDispPointer,
        int fScrollIntoView,
        mol.mshtml._CARET_DIRECTION eDir);

    @VTID(4)
    void moveCaretToPointerEx(
        mol.mshtml.IDisplayPointer pDispPointer,
        int fVisible,
        int fScrollIntoView,
        mol.mshtml._CARET_DIRECTION eDir);

    @VTID(5)
    void moveMarkupPointerToCaret(
        mol.mshtml.IMarkupPointer pIMarkupPointer);

    @VTID(6)
    void moveDisplayPointerToCaret(
        mol.mshtml.IDisplayPointer pDispPointer);

    @VTID(7)
    int isVisible();

    @VTID(8)
    void show(
        int fScrollIntoView);

    @VTID(9)
    void hide();

    @VTID(10)
    void insertText(
        Holder<Short> pText,
        int lLen);

    @VTID(11)
    void scrollIntoView();

    @VTID(13)
    mol.mshtml._CARET_DIRECTION getCaretDirection();

    @VTID(14)
    void setCaretDirection(
        mol.mshtml._CARET_DIRECTION eDir);

}
