package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispCEventObj extends Com4jObject {
    @DISPID(1007)
    @PropPut
    void returnValue(
        java.lang.Object rhs);

    @DISPID(1007)
    @PropGet
    java.lang.Object returnValue();

    @DISPID(1008)
    @PropPut
    void cancelBubble(
        boolean rhs);

    @DISPID(1008)
    @PropGet
    boolean cancelBubble();

    @DISPID(1011)
    @PropPut
    void keyCode(
        int rhs);

    @DISPID(1011)
    @PropGet
    int keyCode();

    @DISPID(-2147417611)
    void setAttribute(
        java.lang.String strAttributeName,
        java.lang.Object attributeValue,
        int lFlags);

    @DISPID(-2147417610)
    java.lang.Object getAttribute(
        java.lang.String strAttributeName,
        int lFlags);

    @DISPID(-2147417609)
    boolean removeAttribute(
        java.lang.String strAttributeName,
        int lFlags);

    @DISPID(1027)
    @PropPut
    void propertyName(
        java.lang.String rhs);

    @DISPID(1027)
    @PropGet
    java.lang.String propertyName();

    @DISPID(1031)
    @PropPut
    void bookmarks(
        mol.mshtml.IHTMLBookmarkCollection rhs);

    @DISPID(1031)
    @PropGet
    mol.mshtml.IHTMLBookmarkCollection bookmarks();

    @DISPID(1032)
    @PropPut
    void recordset(
        com4j.Com4jObject rhs);

    @DISPID(1032)
    @PropGet
    com4j.Com4jObject recordset();

    @DISPID(1033)
    @PropPut
    void dataFld(
        java.lang.String rhs);

    @DISPID(1033)
    @PropGet
    java.lang.String dataFld();

    @DISPID(1034)
    @PropPut
    void boundElements(
        mol.mshtml.IHTMLElementCollection rhs);

    @DISPID(1034)
    @PropGet
    mol.mshtml.IHTMLElementCollection boundElements();

    @DISPID(1035)
    @PropPut
    void repeat(
        boolean rhs);

    @DISPID(1035)
    @PropGet
    boolean repeat();

    @DISPID(1036)
    @PropPut
    void srcUrn(
        java.lang.String rhs);

    @DISPID(1036)
    @PropGet
    java.lang.String srcUrn();

    @DISPID(1001)
    @PropPut
    void srcElement(
        mol.mshtml.IHTMLElement rhs);

    @DISPID(1001)
    @PropGet
    mol.mshtml.IHTMLElement srcElement();

    @DISPID(1002)
    @PropPut
    void altKey(
        boolean rhs);

    @DISPID(1002)
    @PropGet
    boolean altKey();

    @DISPID(1003)
    @PropPut
    void ctrlKey(
        boolean rhs);

    @DISPID(1003)
    @PropGet
    boolean ctrlKey();

    @DISPID(1004)
    @PropPut
    void shiftKey(
        boolean rhs);

    @DISPID(1004)
    @PropGet
    boolean shiftKey();

    @DISPID(1009)
    @PropPut
    void fromElement(
        mol.mshtml.IHTMLElement rhs);

    @DISPID(1009)
    @PropGet
    mol.mshtml.IHTMLElement fromElement();

    @DISPID(1010)
    @PropPut
    void toElement(
        mol.mshtml.IHTMLElement rhs);

    @DISPID(1010)
    @PropGet
    mol.mshtml.IHTMLElement toElement();

    @DISPID(1012)
    @PropPut
    void button(
        int rhs);

    @DISPID(1012)
    @PropGet
    int button();

    @DISPID(1013)
    @PropPut
    void type(
        java.lang.String rhs);

    @DISPID(1013)
    @PropGet
    java.lang.String type();

    @DISPID(1014)
    @PropPut
    void qualifier(
        java.lang.String rhs);

    @DISPID(1014)
    @PropGet
    java.lang.String qualifier();

    @DISPID(1015)
    @PropPut
    void reason(
        int rhs);

    @DISPID(1015)
    @PropGet
    int reason();

    @DISPID(1005)
    @PropPut
    void x(
        int rhs);

    @DISPID(1005)
    @PropGet
    int x();

    @DISPID(1006)
    @PropPut
    void y(
        int rhs);

    @DISPID(1006)
    @PropGet
    int y();

    @DISPID(1020)
    @PropPut
    void clientX(
        int rhs);

    @DISPID(1020)
    @PropGet
    int clientX();

    @DISPID(1021)
    @PropPut
    void clientY(
        int rhs);

    @DISPID(1021)
    @PropGet
    int clientY();

    @DISPID(1022)
    @PropPut
    void offsetX(
        int rhs);

    @DISPID(1022)
    @PropGet
    int offsetX();

    @DISPID(1023)
    @PropPut
    void offsetY(
        int rhs);

    @DISPID(1023)
    @PropGet
    int offsetY();

    @DISPID(1024)
    @PropPut
    void screenX(
        int rhs);

    @DISPID(1024)
    @PropGet
    int screenX();

    @DISPID(1025)
    @PropPut
    void screenY(
        int rhs);

    @DISPID(1025)
    @PropGet
    int screenY();

    @DISPID(1026)
    @PropPut
    void srcFilter(
        com4j.Com4jObject rhs);

    @DISPID(1026)
    @PropGet
    com4j.Com4jObject srcFilter();

    @DISPID(1037)
    @PropGet
    mol.mshtml.IHTMLDataTransfer dataTransfer();

    @DISPID(1038)
    @PropGet
    boolean contentOverflow();

    @DISPID(1039)
    @PropPut
    void shiftLeft(
        boolean rhs);

    @DISPID(1039)
    @PropGet
    boolean shiftLeft();

    @DISPID(1040)
    @PropPut
    void altLeft(
        boolean rhs);

    @DISPID(1040)
    @PropGet
    boolean altLeft();

    @DISPID(1041)
    @PropPut
    void ctrlLeft(
        boolean rhs);

    @DISPID(1041)
    @PropGet
    boolean ctrlLeft();

    @DISPID(1042)
    @PropGet
    int imeCompositionChange();

    @DISPID(1043)
    @PropGet
    int imeNotifyCommand();

    @DISPID(1044)
    @PropGet
    int imeNotifyData();

    @DISPID(1046)
    @PropGet
    int imeRequest();

    @DISPID(1047)
    @PropGet
    int imeRequestData();

    @DISPID(1045)
    @PropGet
    int keyboardLayout();

    @DISPID(1048)
    @PropGet
    int behaviorCookie();

    @DISPID(1049)
    @PropGet
    int behaviorPart();

    @DISPID(1050)
    @PropGet
    java.lang.String nextPage();

    @DISPID(1051)
    @PropGet
    int wheelDelta();

}
