package mol.mshtml  ;

import com4j.*;

@IID("{3050F7FD-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IElementNamespaceFactoryCallback extends Com4jObject {
    @VTID(3)
    void resolve(
        java.lang.String bstrNamespace,
        java.lang.String bstrTagName,
        java.lang.String bstrAttrs,
        mol.mshtml.IElementNamespace pNamespace);

}
