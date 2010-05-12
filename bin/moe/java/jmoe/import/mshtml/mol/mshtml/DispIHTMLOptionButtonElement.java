package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispIHTMLOptionButtonElement extends Com4jObject {
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

    @DISPID(-2147417111)
    @PropPut
    void className(
        java.lang.String rhs);

    @DISPID(-2147417111)
    @PropGet
    java.lang.String className();

    @DISPID(-2147417110)
    @PropPut
    void id(
        java.lang.String rhs);

    @DISPID(-2147417110)
    @PropGet
    java.lang.String id();

    @DISPID(-2147417108)
    @PropGet
    java.lang.String tagName();

    @DISPID(-2147418104)
    @PropGet
    mol.mshtml.IHTMLElement parentElement();

    @DISPID(-2147418038)
    @PropGet
    mol.mshtml.IHTMLStyle style();

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

    @DISPID(-2147412107)
    @PropPut
    void onkeydown(
        java.lang.Object rhs);

    @DISPID(-2147412107)
    @PropGet
    java.lang.Object onkeydown();

    @DISPID(-2147412106)
    @PropPut
    void onkeyup(
        java.lang.Object rhs);

    @DISPID(-2147412106)
    @PropGet
    java.lang.Object onkeyup();

    @DISPID(-2147412105)
    @PropPut
    void onkeypress(
        java.lang.Object rhs);

    @DISPID(-2147412105)
    @PropGet
    java.lang.Object onkeypress();

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

    @DISPID(-2147412108)
    @PropPut
    void onmousemove(
        java.lang.Object rhs);

    @DISPID(-2147412108)
    @PropGet
    java.lang.Object onmousemove();

    @DISPID(-2147412110)
    @PropPut
    void onmousedown(
        java.lang.Object rhs);

    @DISPID(-2147412110)
    @PropGet
    java.lang.Object onmousedown();

    @DISPID(-2147412109)
    @PropPut
    void onmouseup(
        java.lang.Object rhs);

    @DISPID(-2147412109)
    @PropGet
    java.lang.Object onmouseup();

    @DISPID(-2147417094)
    @PropGet
    com4j.Com4jObject document();

    @DISPID(-2147418043)
    @PropPut
    void title(
        java.lang.String rhs);

    @DISPID(-2147418043)
    @PropGet
    java.lang.String title();

    @DISPID(-2147413012)
    @PropPut
    void language(
        java.lang.String rhs);

    @DISPID(-2147413012)
    @PropGet
    java.lang.String language();

    @DISPID(-2147412075)
    @PropPut
    void onselectstart(
        java.lang.Object rhs);

    @DISPID(-2147412075)
    @PropGet
    java.lang.Object onselectstart();

    @DISPID(-2147417093)
    void scrollIntoView(
        java.lang.Object varargStart);

    @DISPID(-2147417092)
    boolean contains(
        mol.mshtml.IHTMLElement pChild);

    @DISPID(-2147417088)
    @PropGet
    int sourceIndex();

    @DISPID(-2147417087)
    @PropGet
    java.lang.Object recordNumber();

    @DISPID(-2147413103)
    @PropPut
    void lang(
        java.lang.String rhs);

    @DISPID(-2147413103)
    @PropGet
    java.lang.String lang();

    @DISPID(-2147417104)
    @PropGet
    int offsetLeft();

    @DISPID(-2147417103)
    @PropGet
    int offsetTop();

    @DISPID(-2147417102)
    @PropGet
    int offsetWidth();

    @DISPID(-2147417101)
    @PropGet
    int offsetHeight();

    @DISPID(-2147417100)
    @PropGet
    mol.mshtml.IHTMLElement offsetParent();

    @DISPID(-2147417086)
    @PropPut
    void innerHTML(
        java.lang.String rhs);

    @DISPID(-2147417086)
    @PropGet
    java.lang.String innerHTML();

    @DISPID(-2147417085)
    @PropPut
    void innerText(
        java.lang.String rhs);

    @DISPID(-2147417085)
    @PropGet
    java.lang.String innerText();

    @DISPID(-2147417084)
    @PropPut
    void outerHTML(
        java.lang.String rhs);

    @DISPID(-2147417084)
    @PropGet
    java.lang.String outerHTML();

    @DISPID(-2147417083)
    @PropPut
    void outerText(
        java.lang.String rhs);

    @DISPID(-2147417083)
    @PropGet
    java.lang.String outerText();

    @DISPID(-2147417082)
    void insertAdjacentHTML(
        java.lang.String where,
        java.lang.String html);

    @DISPID(-2147417081)
    void insertAdjacentText(
        java.lang.String where,
        java.lang.String text);

    @DISPID(-2147417080)
    @PropGet
    mol.mshtml.IHTMLElement parentTextEdit();

    @DISPID(-2147417078)
    @PropGet
    boolean isTextEdit();

    @DISPID(-2147417079)
    void click();

    @DISPID(-2147417077)
    @PropGet
    mol.mshtml.IHTMLFiltersCollection filters();

    @DISPID(-2147412077)
    @PropPut
    void ondragstart(
        java.lang.Object rhs);

    @DISPID(-2147412077)
    @PropGet
    java.lang.Object ondragstart();

    @DISPID(-2147417076)
    java.lang.String toString_();

    @DISPID(-2147412091)
    @PropPut
    void onbeforeupdate(
        java.lang.Object rhs);

    @DISPID(-2147412091)
    @PropGet
    java.lang.Object onbeforeupdate();

    @DISPID(-2147412090)
    @PropPut
    void onafterupdate(
        java.lang.Object rhs);

    @DISPID(-2147412090)
    @PropGet
    java.lang.Object onafterupdate();

    @DISPID(-2147412074)
    @PropPut
    void onerrorupdate(
        java.lang.Object rhs);

    @DISPID(-2147412074)
    @PropGet
    java.lang.Object onerrorupdate();

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

    @DISPID(-2147412069)
    @PropPut
    void onfilterchange(
        java.lang.Object rhs);

    @DISPID(-2147412069)
    @PropGet
    java.lang.Object onfilterchange();

    @DISPID(-2147417075)
    @PropGet
    com4j.Com4jObject children();

    @DISPID(-2147417074)
    @PropGet
    com4j.Com4jObject all();

    @DISPID(-2147418097)
    @PropPut
    void tabIndex(
        short rhs);

    @DISPID(-2147418097)
    @PropGet
    short tabIndex();

    @DISPID(-2147416112)
    void focus();

    @DISPID(-2147416107)
    @PropPut
    void accessKey(
        java.lang.String rhs);

    @DISPID(-2147416107)
    @PropGet
    java.lang.String accessKey();

    @DISPID(-2147412097)
    @PropPut
    void onblur(
        java.lang.Object rhs);

    @DISPID(-2147412097)
    @PropGet
    java.lang.Object onblur();

    @DISPID(-2147412098)
    @PropPut
    void onfocus(
        java.lang.Object rhs);

    @DISPID(-2147412098)
    @PropGet
    java.lang.Object onfocus();

    @DISPID(-2147412076)
    @PropPut
    void onresize(
        java.lang.Object rhs);

    @DISPID(-2147412076)
    @PropGet
    java.lang.Object onresize();

    @DISPID(-2147416110)
    void blur();

    @DISPID(-2147416095)
    void addFilter(
        com4j.Com4jObject pUnk);

    @DISPID(-2147416094)
    void removeFilter(
        com4j.Com4jObject pUnk);

    @DISPID(-2147416093)
    @PropGet
    int clientHeight();

    @DISPID(-2147416092)
    @PropGet
    int clientWidth();

    @DISPID(-2147416091)
    @PropGet
    int clientTop();

    @DISPID(-2147416090)
    @PropGet
    int clientLeft();

    @DISPID(-2147413011)
    @PropPut
    void value(
        java.lang.String rhs);

    @DISPID(-2147413011)
    @PropGet
    java.lang.String value();

    @DISPID(2000)
    @PropGet
    java.lang.String type();

    @DISPID(-2147418112)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(-2147418112)
    @PropGet
    java.lang.String name();

    @DISPID(2009)
    @PropPut
    void checked(
        boolean rhs);

    @DISPID(2009)
    @PropGet
    boolean checked();

    @DISPID(2008)
    @PropPut
    void defaultChecked(
        boolean rhs);

    @DISPID(2008)
    @PropGet
    boolean defaultChecked();

    @DISPID(-2147412082)
    @PropPut
    void onchange(
        java.lang.Object rhs);

    @DISPID(-2147412082)
    @PropGet
    java.lang.Object onchange();

    @DISPID(-2147418036)
    @PropPut
    void disabled(
        boolean rhs);

    @DISPID(-2147418036)
    @PropGet
    boolean disabled();

    @DISPID(2001)
    @PropPut
    void status(
        boolean rhs);

    @DISPID(2001)
    @PropGet
    boolean status();

    @DISPID(2007)
    @PropPut
    void indeterminate(
        boolean rhs);

    @DISPID(2007)
    @PropGet
    boolean indeterminate();

    @DISPID(-2147416108)
    @PropGet
    mol.mshtml.IHTMLFormElement form();

    @DISPID(-2147417091)
    @PropPut
    void dataFld(
        java.lang.String rhs);

    @DISPID(-2147417091)
    @PropGet
    java.lang.String dataFld();

    @DISPID(-2147417090)
    @PropPut
    void dataSrc(
        java.lang.String rhs);

    @DISPID(-2147417090)
    @PropGet
    java.lang.String dataSrc();

    @DISPID(-2147417089)
    @PropPut
    void dataFormatAs(
        java.lang.String rhs);

    @DISPID(-2147417089)
    @PropGet
    java.lang.String dataFormatAs();

}
