package mol.mshtml  ;

import com4j.*;

@IID("{3050F699-98B5-11CF-BB82-00AA00BDCE0B}")
public interface ISelectionServicesListener extends Com4jObject {
    @VTID(3)
    void beginSelectionUndo();

    @VTID(4)
    void endSelectionUndo();

    @VTID(5)
    void onSelectedElementExit(
        mol.mshtml.IMarkupPointer pIElementStart,
        mol.mshtml.IMarkupPointer pIElementEnd,
        mol.mshtml.IMarkupPointer pIElementContentStart,
        mol.mshtml.IMarkupPointer pIElementContentEnd);

    @VTID(6)
    void onChangeType(
        mol.mshtml._SELECTION_TYPE eType,
        mol.mshtml.ISelectionServicesListener pIListener);

    @VTID(7)
    java.lang.String getTypeDetail();

}
