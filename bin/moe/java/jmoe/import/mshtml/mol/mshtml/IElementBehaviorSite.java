package mol.mshtml  ;

import com4j.*;

@IID("{3050F427-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IElementBehaviorSite extends Com4jObject {
    @VTID(3)
    mol.mshtml.IHTMLElement getElement();

    @VTID(4)
    void registerNotification(
        int lEvent);

}
