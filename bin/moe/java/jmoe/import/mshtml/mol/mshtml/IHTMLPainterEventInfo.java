package mol.mshtml  ;

import com4j.*;

@IID("{3050F6DF-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLPainterEventInfo extends Com4jObject {
    @VTID(3)
    int getEventInfoFlags();

    @VTID(4)
    void getEventTarget(
        Holder<mol.mshtml.IHTMLElement> ppElement);

    @VTID(5)
    void setCursor(
        int lPartID);

    @VTID(6)
    java.lang.String stringFromPartID(
        int lPartID);

}
