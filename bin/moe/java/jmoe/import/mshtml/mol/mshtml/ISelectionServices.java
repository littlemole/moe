package mol.mshtml  ;

import com4j.*;

@IID("{3050F684-98B5-11CF-BB82-00AA00BDCE0B}")
public interface ISelectionServices extends Com4jObject {
    @VTID(3)
    void setSelectionType(
        mol.mshtml._SELECTION_TYPE eType,
        mol.mshtml.ISelectionServicesListener pIListener);

    @VTID(4)
    mol.mshtml.IMarkupContainer getMarkupContainer();

    @VTID(5)
    mol.mshtml.ISegment addSegment(
        mol.mshtml.IMarkupPointer pIStart,
        mol.mshtml.IMarkupPointer pIEnd);

    @VTID(6)
    mol.mshtml.IElementSegment addElementSegment(
        mol.mshtml.IHTMLElement pIElement);

    @VTID(7)
    void removeSegment(
        mol.mshtml.ISegment pISegment);

    @VTID(8)
    mol.mshtml.ISelectionServicesListener getSelectionServicesListener();

}
