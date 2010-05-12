package mol.mshtml  ;

import com4j.*;

@IID("{3050F605-98B5-11CF-BB82-00AA00BDCE0B}")
public interface ISegmentList extends Com4jObject {
    @VTID(3)
    mol.mshtml.ISegmentListIterator createIterator();

    @VTID(4)
    mol.mshtml._SELECTION_TYPE getType();

    @VTID(5)
    int isEmpty();

}
