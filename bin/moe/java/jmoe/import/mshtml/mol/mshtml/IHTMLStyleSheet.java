package mol.mshtml  ;

import com4j.*;

@IID("{3050F2E3-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLStyleSheet extends Com4jObject {
    @VTID(7)
    void title(
        java.lang.String p);

    @VTID(8)
    java.lang.String title();

    @VTID(9)
    mol.mshtml.IHTMLStyleSheet parentStyleSheet();

    @VTID(10)
    mol.mshtml.IHTMLElement owningElement();

    @VTID(11)
    void disabled(
        boolean p);

    @VTID(12)
    boolean disabled();

    @VTID(13)
    boolean readOnly();

    @VTID(14)
    mol.mshtml.IHTMLStyleSheetsCollection imports();

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT,defaultPropertyThrough={mol.mshtml.IHTMLStyleSheetsCollection.class})
    java.lang.Object imports(
        java.lang.Object pvarIndex);

    @VTID(15)
    void href(
        java.lang.String p);

    @VTID(16)
    java.lang.String href();

    @VTID(17)
    java.lang.String type();

    @VTID(18)
    java.lang.String id();

    @VTID(19)
    int addImport(
        java.lang.String bstrUrl,
        int lIndex);

    @VTID(20)
    int addRule(
        java.lang.String bstrSelector,
        java.lang.String bstrStyle,
        int lIndex);

    @VTID(21)
    void removeImport(
        int lIndex);

    @VTID(22)
    void removeRule(
        int lIndex);

    @VTID(23)
    void media(
        java.lang.String p);

    @VTID(24)
    java.lang.String media();

    @VTID(25)
    void cssText(
        java.lang.String p);

    @VTID(26)
    java.lang.String cssText();

    @VTID(27)
    mol.mshtml.IHTMLStyleSheetRulesCollection rules();

    @VTID(27)
    @ReturnValue(defaultPropertyThrough={mol.mshtml.IHTMLStyleSheetRulesCollection.class})
    mol.mshtml.IHTMLStyleSheetRule rules(
        int index);

}
