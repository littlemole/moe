package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTMLWindow2 extends Com4jObject {
    @DISPID(0)
    @DefaultMethod
    java.lang.Object item(
        java.lang.Object pvarIndex);

    @DISPID(1001)
    @PropGet
    int length();

    @DISPID(1100)
    @PropGet
    mol.mshtml.IHTMLFramesCollection2 frames();

    @DISPID(1101)
    @PropPut
    void defaultStatus(
        java.lang.String rhs);

    @DISPID(1101)
    @PropGet
    java.lang.String defaultStatus();

    @DISPID(1102)
    @PropPut
    void status(
        java.lang.String rhs);

    @DISPID(1102)
    @PropGet
    java.lang.String status();

    @DISPID(1104)
    void clearTimeout(
        int timerID);

    @DISPID(1105)
    void alert(
        java.lang.String message);

    @DISPID(1110)
    boolean confirm(
        java.lang.String message);

    @DISPID(1111)
    java.lang.Object prompt(
        java.lang.String message,
        java.lang.String defstr);

    @DISPID(1125)
    @PropGet
    mol.mshtml.IHTMLImageElementFactory image();

    @DISPID(14)
    @PropGet
    mol.mshtml.IHTMLLocation location();

    @DISPID(2)
    @PropGet
    mol.mshtml.IOmHistory history();

    @DISPID(3)
    void close();

    @DISPID(4)
    @PropPut
    void opener(
        java.lang.Object rhs);

    @DISPID(4)
    @PropGet
    java.lang.Object opener();

    @DISPID(5)
    @PropGet
    mol.mshtml.IOmNavigator navigator();

    @DISPID(11)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(11)
    @PropGet
    java.lang.String name();

    @DISPID(12)
    @PropGet
    mol.mshtml.IHTMLWindow2 parent();

    @DISPID(13)
    mol.mshtml.IHTMLWindow2 open(
        java.lang.String url,
        java.lang.String name,
        java.lang.String features,
        boolean replace);

    @DISPID(20)
    @PropGet
    mol.mshtml.IHTMLWindow2 self();

    @DISPID(21)
    @PropGet
    mol.mshtml.IHTMLWindow2 top();

    @DISPID(22)
    @PropGet
    mol.mshtml.IHTMLWindow2 window();

    @DISPID(25)
    void navigate(
        java.lang.String url);

    @DISPID(-2147412098)
    @PropPut
    void onfocus(
        java.lang.Object rhs);

    @DISPID(-2147412098)
    @PropGet
    java.lang.Object onfocus();

    @DISPID(-2147412097)
    @PropPut
    void onblur(
        java.lang.Object rhs);

    @DISPID(-2147412097)
    @PropGet
    java.lang.Object onblur();

    @DISPID(-2147412080)
    @PropPut
    void onload(
        java.lang.Object rhs);

    @DISPID(-2147412080)
    @PropGet
    java.lang.Object onload();

    @DISPID(-2147412073)
    @PropPut
    void onbeforeunload(
        java.lang.Object rhs);

    @DISPID(-2147412073)
    @PropGet
    java.lang.Object onbeforeunload();

    @DISPID(-2147412079)
    @PropPut
    void onunload(
        java.lang.Object rhs);

    @DISPID(-2147412079)
    @PropGet
    java.lang.Object onunload();

    @DISPID(-2147412099)
    @PropPut
    void onhelp(
        java.lang.Object rhs);

    @DISPID(-2147412099)
    @PropGet
    java.lang.Object onhelp();

    @DISPID(-2147412083)
    @PropPut
    void onerror(
        java.lang.Object rhs);

    @DISPID(-2147412083)
    @PropGet
    java.lang.Object onerror();

    @DISPID(-2147412076)
    @PropPut
    void onresize(
        java.lang.Object rhs);

    @DISPID(-2147412076)
    @PropGet
    java.lang.Object onresize();

    @DISPID(-2147412081)
    @PropPut
    void onscroll(
        java.lang.Object rhs);

    @DISPID(-2147412081)
    @PropGet
    java.lang.Object onscroll();

    @DISPID(1151)
    @PropGet
    mol.mshtml.IHTMLDocument2 document();

    @DISPID(1152)
    @PropGet
    mol.mshtml.IHTMLEventObj event();

    @DISPID(1153)
    @PropGet
    com4j.Com4jObject _newEnum();

    @DISPID(1154)
    java.lang.Object showModalDialog(
        java.lang.String dialog,
        java.lang.Object varArgIn,
        java.lang.Object varOptions);

    @DISPID(1155)
    void showHelp(
        java.lang.String helpURL,
        java.lang.Object helpArg,
        java.lang.String features);

    @DISPID(1156)
    @PropGet
    mol.mshtml.IHTMLScreen screen();

    @DISPID(1157)
    @PropGet
    mol.mshtml.IHTMLOptionElementFactory option();

    @DISPID(1158)
    void focus();

    @DISPID(23)
    @PropGet
    boolean closed();

    @DISPID(1159)
    void blur();

    @DISPID(1160)
    void scroll(
        int x,
        int y);

    @DISPID(1161)
    @PropGet
    mol.mshtml.IOmNavigator clientInformation();

    @DISPID(1163)
    void clearInterval(
        int timerID);

    @DISPID(1164)
    @PropPut
    void offscreenBuffering(
        java.lang.Object rhs);

    @DISPID(1164)
    @PropGet
    java.lang.Object offscreenBuffering();

    @DISPID(1165)
    java.lang.Object execScript(
        java.lang.String code,
        java.lang.String language);

    @DISPID(1166)
    java.lang.String toString_();

    @DISPID(1167)
    void scrollBy(
        int x,
        int y);

    @DISPID(1168)
    void scrollTo(
        int x,
        int y);

    @DISPID(6)
    void moveTo(
        int x,
        int y);

    @DISPID(7)
    void moveBy(
        int x,
        int y);

    @DISPID(9)
    void resizeTo(
        int x,
        int y);

    @DISPID(8)
    void resizeBy(
        int x,
        int y);

    @DISPID(1169)
    @PropGet
    com4j.Com4jObject external();

    @DISPID(1170)
    @PropGet
    int screenLeft();

    @DISPID(1171)
    @PropGet
    int screenTop();

    @DISPID(-2147417605)
    boolean attachEvent(
        java.lang.String event,
        com4j.Com4jObject pdisp);

    @DISPID(-2147417604)
    void detachEvent(
        java.lang.String event,
        com4j.Com4jObject pdisp);

    @DISPID(1103)
    int setTimeout(
        java.lang.Object expression,
        int msec,
        java.lang.Object language);

    @DISPID(1162)
    int setInterval(
        java.lang.Object expression,
        int msec,
        java.lang.Object language);

    @DISPID(1174)
    void print();

    @DISPID(-2147412046)
    @PropPut
    void onbeforeprint(
        java.lang.Object rhs);

    @DISPID(-2147412046)
    @PropGet
    java.lang.Object onbeforeprint();

    @DISPID(-2147412045)
    @PropPut
    void onafterprint(
        java.lang.Object rhs);

    @DISPID(-2147412045)
    @PropGet
    java.lang.Object onafterprint();

    @DISPID(1175)
    @PropGet
    mol.mshtml.IHTMLDataTransfer clipboardData();

    @DISPID(1176)
    mol.mshtml.IHTMLWindow2 showModelessDialog(
        java.lang.String url,
        java.lang.Object varArgIn,
        java.lang.Object options);

    @DISPID(1180)
    com4j.Com4jObject createPopup(
        java.lang.Object varArgIn);

    @DISPID(1181)
    @PropGet
    mol.mshtml.IHTMLFrameBase frameElement();

    @DISPID(1190)
    @PropPut
    void xmlHttpRequest(
        java.lang.Object rhs);

    @DISPID(1190)
    @PropGet
    java.lang.Object xmlHttpRequest();

}
