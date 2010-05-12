package mol.mshtml  ;

import com4j.*;

@IID("{3050F663-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLEditServices extends Com4jObject {
    @VTID(3)
    void addDesigner(
        mol.mshtml.IHTMLEditDesigner pIDesigner);

    @VTID(4)
    void removeDesigner(
        mol.mshtml.IHTMLEditDesigner pIDesigner);

    @VTID(5)
    mol.mshtml.ISelectionServices getSelectionServices(
        mol.mshtml.IMarkupContainer pIContainer);

    @VTID(6)
    void moveToSelectionAnchor(
        mol.mshtml.IMarkupPointer pIStartAnchor);

    @VTID(7)
    void moveToSelectionEnd(
        mol.mshtml.IMarkupPointer pIEndAnchor);

    @VTID(8)
    void selectRange(
        mol.mshtml.IMarkupPointer pStart,
        mol.mshtml.IMarkupPointer pEnd,
        mol.mshtml._SELECTION_TYPE eType);

}
