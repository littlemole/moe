package mol.mshtml  ;

import com4j.*;

@IID("{3050F68F-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IElementSegment extends mol.mshtml.ISegment {
    @VTID(4)
    mol.mshtml.IHTMLElement getElement();

    @VTID(5)
    void setPrimary(
        int fPrimary);

    @VTID(6)
    int isPrimary();

}
