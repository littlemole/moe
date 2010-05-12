package mol.mshtml  ;

import com4j.*;

@IID("{3050F425-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IElementBehavior extends Com4jObject {
    @VTID(3)
    void init(
        mol.mshtml.IElementBehaviorSite pBehaviorSite);

    @VTID(4)
    void notify_(
        int lEvent,
        java.lang.Object pVar);

    @VTID(5)
    void detach();

}
