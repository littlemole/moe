package mol.mshtml  ;

import com4j.*;

@IID("{3050F429-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IElementBehaviorFactory extends Com4jObject {
    @VTID(3)
    mol.mshtml.IElementBehavior findBehavior(
        java.lang.String bstrBehavior,
        java.lang.String bstrBehaviorUrl,
        mol.mshtml.IElementBehaviorSite pSite);

}
