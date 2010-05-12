package mol.mshtml  ;

import com4j.*;

@IID("{3050F606-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHighlightRenderingServices extends Com4jObject {
    @VTID(3)
    mol.mshtml.IHighlightSegment addSegment(
        mol.mshtml.IDisplayPointer pDispPointerStart,
        mol.mshtml.IDisplayPointer pDispPointerEnd,
        mol.mshtml.IHTMLRenderStyle pIRenderStyle);

    @VTID(4)
    void moveSegmentToPointers(
        mol.mshtml.IHighlightSegment pISegment,
        mol.mshtml.IDisplayPointer pDispPointerStart,
        mol.mshtml.IDisplayPointer pDispPointerEnd);

    @VTID(5)
    void removeSegment(
        mol.mshtml.IHighlightSegment pISegment);

}
