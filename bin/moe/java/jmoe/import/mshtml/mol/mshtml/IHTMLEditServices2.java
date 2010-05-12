package mol.mshtml  ;

import com4j.*;

@IID("{3050F812-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLEditServices2 extends mol.mshtml.IHTMLEditServices {
    @VTID(9)
    void moveToSelectionAnchorEx(
        mol.mshtml.IDisplayPointer pIStartAnchor);

    @VTID(10)
    void moveToSelectionEndEx(
        mol.mshtml.IDisplayPointer pIEndAnchor);

    @VTID(11)
    void freezeVirtualCaretPos(
        int fReCompute);

    @VTID(12)
    void unFreezeVirtualCaretPos(
        int fReset);

}
