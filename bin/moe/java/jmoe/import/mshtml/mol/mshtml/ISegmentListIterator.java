package mol.mshtml  ;

import com4j.*;

@IID("{3050F692-98B5-11CF-BB82-00AA00BDCE0B}")
public interface ISegmentListIterator extends Com4jObject {
    @VTID(3)
    mol.mshtml.ISegment current();

    @VTID(4)
    void first();

    @VTID(5)
    void isDone();

    @VTID(6)
    void advance();

}
