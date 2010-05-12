package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTMLDefaults extends Com4jObject {
    @DISPID(1001)
    @PropGet
    mol.mshtml.IHTMLStyle style();

    @DISPID(1002)
    @PropPut
    void tabStop(
        boolean rhs);

    @DISPID(1002)
    @PropGet
    boolean tabStop();

    @DISPID(-2147412913)
    @PropPut
    void viewInheritStyle(
        boolean rhs);

    @DISPID(-2147412913)
    @PropGet
    boolean viewInheritStyle();

    @DISPID(1006)
    @PropPut
    void viewMasterTab(
        boolean rhs);

    @DISPID(1006)
    @PropGet
    boolean viewMasterTab();

    @DISPID(1003)
    @PropPut
    void scrollSegmentX(
        int rhs);

    @DISPID(1003)
    @PropGet
    int scrollSegmentX();

    @DISPID(1004)
    @PropPut
    void scrollSegmentY(
        int rhs);

    @DISPID(1004)
    @PropGet
    int scrollSegmentY();

    @DISPID(1008)
    @PropPut
    void isMultiLine(
        boolean rhs);

    @DISPID(1008)
    @PropGet
    boolean isMultiLine();

    @DISPID(-2147412950)
    @PropPut
    void contentEditable(
        java.lang.String rhs);

    @DISPID(-2147412950)
    @PropGet
    java.lang.String contentEditable();

    @DISPID(1009)
    @PropPut
    void canHaveHTML(
        boolean rhs);

    @DISPID(1009)
    @PropGet
    boolean canHaveHTML();

    @DISPID(1011)
    @PropPut
    void viewLink(
        mol.mshtml.IHTMLDocument rhs);

    @DISPID(1011)
    @PropGet
    mol.mshtml.IHTMLDocument viewLink();

    @DISPID(-2147412914)
    @PropPut
    void frozen(
        boolean rhs);

    @DISPID(-2147412914)
    @PropGet
    boolean frozen();

}
