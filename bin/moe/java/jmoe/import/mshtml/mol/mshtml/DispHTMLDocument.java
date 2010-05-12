package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTMLDocument extends Com4jObject {
    @DISPID(1001)
    @PropGet
    com4j.Com4jObject script();

    @DISPID(1003)
    @PropGet
    mol.mshtml.IHTMLElementCollection all();

    @DISPID(1004)
    @PropGet
    mol.mshtml.IHTMLElement body();

    @DISPID(1005)
    @PropGet
    mol.mshtml.IHTMLElement activeElement();

    @DISPID(1011)
    @PropGet
    mol.mshtml.IHTMLElementCollection images();

    @DISPID(1008)
    @PropGet
    mol.mshtml.IHTMLElementCollection applets();

    @DISPID(1009)
    @PropGet
    mol.mshtml.IHTMLElementCollection links();

    @DISPID(1010)
    @PropGet
    mol.mshtml.IHTMLElementCollection forms();

    @DISPID(1007)
    @PropGet
    mol.mshtml.IHTMLElementCollection anchors();

    @DISPID(1012)
    @PropPut
    void title(
        java.lang.String rhs);

    @DISPID(1012)
    @PropGet
    java.lang.String title();

    @DISPID(1013)
    @PropGet
    mol.mshtml.IHTMLElementCollection scripts();

    @DISPID(1014)
    @PropPut
    void designMode(
        java.lang.String rhs);

    @DISPID(1014)
    @PropGet
    java.lang.String designMode();

    @DISPID(1017)
    @PropGet
    mol.mshtml.IHTMLSelectionObject selection();

    @DISPID(1018)
    @PropGet
    java.lang.String readyState();

    @DISPID(1019)
    @PropGet
    mol.mshtml.IHTMLFramesCollection2 frames();

    @DISPID(1015)
    @PropGet
    mol.mshtml.IHTMLElementCollection embeds();

    @DISPID(1021)
    @PropGet
    mol.mshtml.IHTMLElementCollection plugins();

    @DISPID(1022)
    @PropPut
    void alinkColor(
        java.lang.Object rhs);

    @DISPID(1022)
    @PropGet
    java.lang.Object alinkColor();

    @DISPID(-501)
    @PropPut
    void bgColor(
        java.lang.Object rhs);

    @DISPID(-501)
    @PropGet
    java.lang.Object bgColor();

    @DISPID(-2147413110)
    @PropPut
    void fgColor(
        java.lang.Object rhs);

    @DISPID(-2147413110)
    @PropGet
    java.lang.Object fgColor();

    @DISPID(1024)
    @PropPut
    void linkColor(
        java.lang.Object rhs);

    @DISPID(1024)
    @PropGet
    java.lang.Object linkColor();

    @DISPID(1023)
    @PropPut
    void vlinkColor(
        java.lang.Object rhs);

    @DISPID(1023)
    @PropGet
    java.lang.Object vlinkColor();

    @DISPID(1027)
    @PropGet
    java.lang.String referrer();

    @DISPID(1026)
    @PropGet
    mol.mshtml.IHTMLLocation location();

    @DISPID(1028)
    @PropGet
    java.lang.String lastModified();

    @DISPID(1025)
    @PropPut
    void url(
        java.lang.String rhs);

    @DISPID(1025)
    @PropGet
    java.lang.String url();

    @DISPID(1029)
    @PropPut
    void domain(
        java.lang.String rhs);

    @DISPID(1029)
    @PropGet
    java.lang.String domain();

    @DISPID(1030)
    @PropPut
    void cookie(
        java.lang.String rhs);

    @DISPID(1030)
    @PropGet
    java.lang.String cookie();

    @DISPID(1031)
    @PropPut
    void expando(
        boolean rhs);

    @DISPID(1031)
    @PropGet
    boolean expando();

    @DISPID(1032)
    @PropPut
    void charset(
        java.lang.String rhs);

    @DISPID(1032)
    @PropGet
    java.lang.String charset();

    @DISPID(1033)
    @PropPut
    void defaultCharset(
        java.lang.String rhs);

    @DISPID(1033)
    @PropGet
    java.lang.String defaultCharset();

    @DISPID(1041)
    @PropGet
    java.lang.String mimeType();

    @DISPID(1042)
    @PropGet
    java.lang.String fileSize();

    @DISPID(1043)
    @PropGet
    java.lang.String fileCreatedDate();

    @DISPID(1044)
    @PropGet
    java.lang.String fileModifiedDate();

    @DISPID(1045)
    @PropGet
    java.lang.String fileUpdatedDate();

    @DISPID(1046)
    @PropGet
    java.lang.String security();

    @DISPID(1047)
    @PropGet
    java.lang.String protocol();

    @DISPID(1048)
    @PropGet
    java.lang.String nameProp();

    @DISPID(1054)
    void write(
        java.lang.Object... psarray);

    @DISPID(1055)
    void writeln(
        java.lang.Object... psarray);

    @DISPID(1056)
    com4j.Com4jObject open(
        java.lang.String url,
        java.lang.Object name,
        java.lang.Object features,
        java.lang.Object replace);

    @DISPID(1057)
    void close();

    @DISPID(1058)
    void clear();

    @DISPID(1059)
    boolean queryCommandSupported(
        java.lang.String cmdID);

    @DISPID(1060)
    boolean queryCommandEnabled(
        java.lang.String cmdID);

    @DISPID(1061)
    boolean queryCommandState(
        java.lang.String cmdID);

    @DISPID(1062)
    boolean queryCommandIndeterm(
        java.lang.String cmdID);

    @DISPID(1063)
    java.lang.String queryCommandText(
        java.lang.String cmdID);

    @DISPID(1064)
    java.lang.Object queryCommandValue(
        java.lang.String cmdID);

    @DISPID(1065)
    boolean execCommand(
        java.lang.String cmdID,
        boolean showUI,
        java.lang.Object value);

    @DISPID(1066)
    boolean execCommandShowHelp(
        java.lang.String cmdID);

    @DISPID(1067)
    mol.mshtml.IHTMLElement createElement(
        java.lang.String eTag);

    @DISPID(-2147412099)
    @PropPut
    void onhelp(
        java.lang.Object rhs);

    @DISPID(-2147412099)
    @PropGet
    java.lang.Object onhelp();

    @DISPID(-2147412104)
    @PropPut
    void onclick(
        java.lang.Object rhs);

    @DISPID(-2147412104)
    @PropGet
    java.lang.Object onclick();

    @DISPID(-2147412103)
    @PropPut
    void ondblclick(
        java.lang.Object rhs);

    @DISPID(-2147412103)
    @PropGet
    java.lang.Object ondblclick();

    @DISPID(-2147412106)
    @PropPut
    void onkeyup(
        java.lang.Object rhs);

    @DISPID(-2147412106)
    @PropGet
    java.lang.Object onkeyup();

    @DISPID(-2147412107)
    @PropPut
    void onkeydown(
        java.lang.Object rhs);

    @DISPID(-2147412107)
    @PropGet
    java.lang.Object onkeydown();

    @DISPID(-2147412105)
    @PropPut
    void onkeypress(
        java.lang.Object rhs);

    @DISPID(-2147412105)
    @PropGet
    java.lang.Object onkeypress();

    @DISPID(-2147412109)
    @PropPut
    void onmouseup(
        java.lang.Object rhs);

    @DISPID(-2147412109)
    @PropGet
    java.lang.Object onmouseup();

    @DISPID(-2147412110)
    @PropPut
    void onmousedown(
        java.lang.Object rhs);

    @DISPID(-2147412110)
    @PropGet
    java.lang.Object onmousedown();

    @DISPID(-2147412108)
    @PropPut
    void onmousemove(
        java.lang.Object rhs);

    @DISPID(-2147412108)
    @PropGet
    java.lang.Object onmousemove();

    @DISPID(-2147412111)
    @PropPut
    void onmouseout(
        java.lang.Object rhs);

    @DISPID(-2147412111)
    @PropGet
    java.lang.Object onmouseout();

    @DISPID(-2147412112)
    @PropPut
    void onmouseover(
        java.lang.Object rhs);

    @DISPID(-2147412112)
    @PropGet
    java.lang.Object onmouseover();

    @DISPID(-2147412087)
    @PropPut
    void onreadystatechange(
        java.lang.Object rhs);

    @DISPID(-2147412087)
    @PropGet
    java.lang.Object onreadystatechange();

    @DISPID(-2147412090)
    @PropPut
    void onafterupdate(
        java.lang.Object rhs);

    @DISPID(-2147412090)
    @PropGet
    java.lang.Object onafterupdate();

    @DISPID(-2147412094)
    @PropPut
    void onrowexit(
        java.lang.Object rhs);

    @DISPID(-2147412094)
    @PropGet
    java.lang.Object onrowexit();

    @DISPID(-2147412093)
    @PropPut
    void onrowenter(
        java.lang.Object rhs);

    @DISPID(-2147412093)
    @PropGet
    java.lang.Object onrowenter();

    @DISPID(-2147412077)
    @PropPut
    void ondragstart(
        java.lang.Object rhs);

    @DISPID(-2147412077)
    @PropGet
    java.lang.Object ondragstart();

    @DISPID(-2147412075)
    @PropPut
    void onselectstart(
        java.lang.Object rhs);

    @DISPID(-2147412075)
    @PropGet
    java.lang.Object onselectstart();

    @DISPID(1068)
    mol.mshtml.IHTMLElement elementFromPoint(
        int x,
        int y);

    @DISPID(1034)
    @PropGet
    mol.mshtml.IHTMLWindow2 parentWindow();

    @DISPID(1069)
    @PropGet
    mol.mshtml.IHTMLStyleSheetsCollection styleSheets();

    @DISPID(-2147412091)
    @PropPut
    void onbeforeupdate(
        java.lang.Object rhs);

    @DISPID(-2147412091)
    @PropGet
    java.lang.Object onbeforeupdate();

    @DISPID(-2147412074)
    @PropPut
    void onerrorupdate(
        java.lang.Object rhs);

    @DISPID(-2147412074)
    @PropGet
    java.lang.Object onerrorupdate();

    @DISPID(1070)
    java.lang.String toString_();

    @DISPID(1071)
    mol.mshtml.IHTMLStyleSheet createStyleSheet(
        java.lang.String bstrHref,
        int lIndex);

    @DISPID(1072)
    void releaseCapture();

    @DISPID(1073)
    void recalc(
        boolean fForce);

    @DISPID(1074)
    mol.mshtml.IHTMLDOMNode createTextNode(
        java.lang.String text);

    @DISPID(1075)
    @PropGet
    mol.mshtml.IHTMLElement documentElement();

    @DISPID(1077)
    @PropGet
    java.lang.String uniqueID();

    @DISPID(-2147417605)
    boolean attachEvent(
        java.lang.String event,
        com4j.Com4jObject pdisp);

    @DISPID(-2147417604)
    void detachEvent(
        java.lang.String event,
        com4j.Com4jObject pdisp);

    @DISPID(-2147412050)
    @PropPut
    void onrowsdelete(
        java.lang.Object rhs);

    @DISPID(-2147412050)
    @PropGet
    java.lang.Object onrowsdelete();

    @DISPID(-2147412049)
    @PropPut
    void onrowsinserted(
        java.lang.Object rhs);

    @DISPID(-2147412049)
    @PropGet
    java.lang.Object onrowsinserted();

    @DISPID(-2147412048)
    @PropPut
    void oncellchange(
        java.lang.Object rhs);

    @DISPID(-2147412048)
    @PropGet
    java.lang.Object oncellchange();

    @DISPID(-2147412072)
    @PropPut
    void ondatasetchanged(
        java.lang.Object rhs);

    @DISPID(-2147412072)
    @PropGet
    java.lang.Object ondatasetchanged();

    @DISPID(-2147412071)
    @PropPut
    void ondataavailable(
        java.lang.Object rhs);

    @DISPID(-2147412071)
    @PropGet
    java.lang.Object ondataavailable();

    @DISPID(-2147412070)
    @PropPut
    void ondatasetcomplete(
        java.lang.Object rhs);

    @DISPID(-2147412070)
    @PropGet
    java.lang.Object ondatasetcomplete();

    @DISPID(-2147412065)
    @PropPut
    void onpropertychange(
        java.lang.Object rhs);

    @DISPID(-2147412065)
    @PropGet
    java.lang.Object onpropertychange();

    @DISPID(-2147412995)
    @PropPut
    void dir(
        java.lang.String rhs);

    @DISPID(-2147412995)
    @PropGet
    java.lang.String dir();

    @DISPID(-2147412047)
    @PropPut
    void oncontextmenu(
        java.lang.Object rhs);

    @DISPID(-2147412047)
    @PropGet
    java.lang.Object oncontextmenu();

    @DISPID(-2147412044)
    @PropPut
    void onstop(
        java.lang.Object rhs);

    @DISPID(-2147412044)
    @PropGet
    java.lang.Object onstop();

    @DISPID(1076)
    mol.mshtml.IHTMLDocument2 createDocumentFragment();

    @DISPID(1078)
    @PropGet
    mol.mshtml.IHTMLDocument2 parentDocument();

    @DISPID(1079)
    @PropPut
    void enableDownload(
        boolean rhs);

    @DISPID(1079)
    @PropGet
    boolean enableDownload();

    @DISPID(1080)
    @PropPut
    void baseUrl(
        java.lang.String rhs);

    @DISPID(1080)
    @PropGet
    java.lang.String baseUrl();

    @DISPID(1082)
    @PropPut
    void inheritStyleSheets(
        boolean rhs);

    @DISPID(1082)
    @PropGet
    boolean inheritStyleSheets();

    @DISPID(-2147412043)
    @PropPut
    void onbeforeeditfocus(
        java.lang.Object rhs);

    @DISPID(-2147412043)
    @PropGet
    java.lang.Object onbeforeeditfocus();

    @DISPID(1086)
    mol.mshtml.IHTMLElementCollection getElementsByName(
        java.lang.String v);

    @DISPID(1088)
    mol.mshtml.IHTMLElement getElementById(
        java.lang.String v);

    @DISPID(1087)
    mol.mshtml.IHTMLElementCollection getElementsByTagName(
        java.lang.String v);

    @DISPID(1089)
    void focus();

    @DISPID(1090)
    boolean hasFocus();

    @DISPID(-2147412032)
    @PropPut
    void onselectionchange(
        java.lang.Object rhs);

    @DISPID(-2147412032)
    @PropGet
    java.lang.Object onselectionchange();

    @DISPID(1091)
    @PropGet
    com4j.Com4jObject namespaces();

    @DISPID(1092)
    mol.mshtml.IHTMLDocument2 createDocumentFromUrl(
        java.lang.String bstrUrl,
        java.lang.String bstrOptions);

    @DISPID(1093)
    @PropPut
    void media(
        java.lang.String rhs);

    @DISPID(1093)
    @PropGet
    java.lang.String media();

    @DISPID(1094)
    mol.mshtml.IHTMLEventObj createEventObject(
        java.lang.Object pvarEventObject);

    @DISPID(1095)
    boolean fireEvent(
        java.lang.String bstrEventName,
        java.lang.Object pvarEventObject);

    @DISPID(1096)
    mol.mshtml.IHTMLRenderStyle createRenderStyle(
        java.lang.String v);

    @DISPID(-2147412033)
    @PropPut
    void oncontrolselect(
        java.lang.Object rhs);

    @DISPID(-2147412033)
    @PropGet
    java.lang.Object oncontrolselect();

    @DISPID(1097)
    @PropGet
    java.lang.String urlUnencoded();

    @DISPID(-2147412036)
    @PropPut
    void onmousewheel(
        java.lang.Object rhs);

    @DISPID(-2147412036)
    @PropGet
    java.lang.Object onmousewheel();

    @DISPID(1098)
    @PropGet
    mol.mshtml.IHTMLDOMNode doctype();

    @DISPID(1099)
    @PropGet
    mol.mshtml.IHTMLDOMImplementation implementation();

    @DISPID(1100)
    mol.mshtml.IHTMLDOMAttribute createAttribute(
        java.lang.String bstrattrName);

    @DISPID(1101)
    mol.mshtml.IHTMLDOMNode createComment(
        java.lang.String bstrdata);

    @DISPID(-2147412021)
    @PropPut
    void onfocusin(
        java.lang.Object rhs);

    @DISPID(-2147412021)
    @PropGet
    java.lang.Object onfocusin();

    @DISPID(-2147412020)
    @PropPut
    void onfocusout(
        java.lang.Object rhs);

    @DISPID(-2147412020)
    @PropGet
    java.lang.Object onfocusout();

    @DISPID(-2147412025)
    @PropPut
    void onactivate(
        java.lang.Object rhs);

    @DISPID(-2147412025)
    @PropGet
    java.lang.Object onactivate();

    @DISPID(-2147412024)
    @PropPut
    void ondeactivate(
        java.lang.Object rhs);

    @DISPID(-2147412024)
    @PropGet
    java.lang.Object ondeactivate();

    @DISPID(-2147412022)
    @PropPut
    void onbeforeactivate(
        java.lang.Object rhs);

    @DISPID(-2147412022)
    @PropGet
    java.lang.Object onbeforeactivate();

    @DISPID(-2147412035)
    @PropPut
    void onbeforedeactivate(
        java.lang.Object rhs);

    @DISPID(-2147412035)
    @PropGet
    java.lang.Object onbeforedeactivate();

    @DISPID(1102)
    @PropGet
    java.lang.String compatMode();

    @DISPID(-2147417066)
    @PropGet
    int nodeType();

    @DISPID(-2147417065)
    @PropGet
    mol.mshtml.IHTMLDOMNode parentNode();

    @DISPID(-2147417064)
    boolean hasChildNodes();

    @DISPID(-2147417063)
    @PropGet
    com4j.Com4jObject childNodes();

    @DISPID(-2147417062)
    @PropGet
    com4j.Com4jObject attributes();

    @DISPID(-2147417061)
    mol.mshtml.IHTMLDOMNode insertBefore(
        mol.mshtml.IHTMLDOMNode newChild,
        java.lang.Object refChild);

    @DISPID(-2147417060)
    mol.mshtml.IHTMLDOMNode removeChild(
        mol.mshtml.IHTMLDOMNode oldChild);

    @DISPID(-2147417059)
    mol.mshtml.IHTMLDOMNode replaceChild(
        mol.mshtml.IHTMLDOMNode newChild,
        mol.mshtml.IHTMLDOMNode oldChild);

    @DISPID(-2147417051)
    mol.mshtml.IHTMLDOMNode cloneNode(
        boolean fDeep);

    @DISPID(-2147417046)
    mol.mshtml.IHTMLDOMNode removeNode(
        boolean fDeep);

    @DISPID(-2147417044)
    mol.mshtml.IHTMLDOMNode swapNode(
        mol.mshtml.IHTMLDOMNode otherNode);

    @DISPID(-2147417045)
    mol.mshtml.IHTMLDOMNode replaceNode(
        mol.mshtml.IHTMLDOMNode replacement);

    @DISPID(-2147417039)
    mol.mshtml.IHTMLDOMNode appendChild(
        mol.mshtml.IHTMLDOMNode newChild);

    @DISPID(-2147417038)
    @PropGet
    java.lang.String nodeName();

    @DISPID(-2147417037)
    @PropPut
    void nodeValue(
        java.lang.Object rhs);

    @DISPID(-2147417037)
    @PropGet
    java.lang.Object nodeValue();

    @DISPID(-2147417036)
    @PropGet
    mol.mshtml.IHTMLDOMNode firstChild();

    @DISPID(-2147417035)
    @PropGet
    mol.mshtml.IHTMLDOMNode lastChild();

    @DISPID(-2147417034)
    @PropGet
    mol.mshtml.IHTMLDOMNode previousSibling();

    @DISPID(-2147417033)
    @PropGet
    mol.mshtml.IHTMLDOMNode nextSibling();

    @DISPID(-2147416999)
    @PropGet
    com4j.Com4jObject ownerDocument();

}
