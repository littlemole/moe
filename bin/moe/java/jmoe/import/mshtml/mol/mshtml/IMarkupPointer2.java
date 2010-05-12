package mol.mshtml  ;

import com4j.*;

@IID("{3050F675-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IMarkupPointer2 extends mol.mshtml.IMarkupPointer {
    @VTID(24)
    int isAtWordBreak();

    @VTID(25)
    int getMarkupPosition();

    @VTID(26)
    void moveToMarkupPosition(
        mol.mshtml.IMarkupContainer pContainer,
        int lMP);

    @VTID(27)
    void moveUnitBounded(
        mol.mshtml._MOVEUNIT_ACTION muAction,
        mol.mshtml.IMarkupPointer pIBoundary);

    @VTID(28)
    int isInsideURL(
        mol.mshtml.IMarkupPointer pRight);

    @VTID(29)
    void moveToContent(
        mol.mshtml.IHTMLElement pIElement,
        int fAtStart);

}
