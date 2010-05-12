package mol.mshtml  ;

import com4j.*;

@IID("{3050F80A-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLAttributeCollection2 extends Com4jObject {
    @VTID(7)
    mol.mshtml.IHTMLDOMAttribute getNamedItem(
        java.lang.String bstrName);

    @VTID(8)
    mol.mshtml.IHTMLDOMAttribute setNamedItem(
        mol.mshtml.IHTMLDOMAttribute ppNode);

    @VTID(9)
    mol.mshtml.IHTMLDOMAttribute removeNamedItem(
        java.lang.String bstrName);

}
