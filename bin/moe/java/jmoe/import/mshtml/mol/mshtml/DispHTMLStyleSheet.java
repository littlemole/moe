package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTMLStyleSheet extends Com4jObject {
    @DISPID(1001)
    @PropPut
    void title(
        java.lang.String rhs);

    @DISPID(1001)
    @PropGet
    java.lang.String title();

    @DISPID(1002)
    @PropGet
    mol.mshtml.IHTMLStyleSheet parentStyleSheet();

    @DISPID(1003)
    @PropGet
    mol.mshtml.IHTMLElement owningElement();

    @DISPID(-2147418036)
    @PropPut
    void disabled(
        boolean rhs);

    @DISPID(-2147418036)
    @PropGet
    boolean disabled();

    @DISPID(1004)
    @PropGet
    boolean readOnly();

    @DISPID(1005)
    @PropGet
    mol.mshtml.IHTMLStyleSheetsCollection imports();

    @DISPID(1006)
    @PropPut
    void href(
        java.lang.String rhs);

    @DISPID(1006)
    @PropGet
    java.lang.String href();

    @DISPID(1007)
    @PropGet
    java.lang.String type();

    @DISPID(1008)
    @PropGet
    java.lang.String id();

    @DISPID(1009)
    int addImport(
        java.lang.String bstrUrl,
        int lIndex);

    @DISPID(1010)
    int addRule(
        java.lang.String bstrSelector,
        java.lang.String bstrStyle,
        int lIndex);

    @DISPID(1011)
    void removeImport(
        int lIndex);

    @DISPID(1012)
    void removeRule(
        int lIndex);

    @DISPID(1013)
    @PropPut
    void media(
        java.lang.String rhs);

    @DISPID(1013)
    @PropGet
    java.lang.String media();

    @DISPID(1014)
    @PropPut
    void cssText(
        java.lang.String rhs);

    @DISPID(1014)
    @PropGet
    java.lang.String cssText();

    @DISPID(1015)
    @PropGet
    mol.mshtml.IHTMLStyleSheetRulesCollection rules();

    @DISPID(1016)
    @PropGet
    mol.mshtml.IHTMLStyleSheetPagesCollection pages();

    @DISPID(1017)
    int addPageRule(
        java.lang.String bstrSelector,
        java.lang.String bstrStyle,
        int lIndex);

}
