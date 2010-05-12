package mol.mshtml  ;

import com4j.*;

@IID("{3050F648-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IMarkupContainer2 extends mol.mshtml.IMarkupContainer {
    @VTID(4)
    @ReturnValue(index=1)
    mol.mshtml.IHTMLChangeLog createChangeLog(
        mol.mshtml.IHTMLChangeSink pChangeSink,
        int fForward,
        int fBackward);

    @VTID(5)
    int registerForDirtyRange(
        mol.mshtml.IHTMLChangeSink pChangeSink);

    @VTID(6)
    void unRegisterForDirtyRange(
        int dwCookie);

    @VTID(7)
    void getAndClearDirtyRange(
        int dwCookie,
        mol.mshtml.IMarkupPointer pIPointerBegin,
        mol.mshtml.IMarkupPointer pIPointerEnd);

    @VTID(8)
    void getVersionNumber();

    @VTID(9)
    mol.mshtml.IHTMLElement getMasterElement();

}
