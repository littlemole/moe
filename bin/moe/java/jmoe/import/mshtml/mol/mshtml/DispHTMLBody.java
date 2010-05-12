package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTMLBody extends Com4jObject {
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

    @DISPID(-2147417073)
    @PropGet
    java.lang.String scopeName();

    @DISPID(-2147417072)
    void setCapture(
        boolean containerCapture);

    @DISPID(-2147417071)
    void releaseCapture();

    @DISPID(-2147412066)
    @PropPut
    void onlosecapture(
        java.lang.Object rhs);

    @DISPID(-2147412066)
    @PropGet
    java.lang.Object onlosecapture();

    @DISPID(-2147417070)
    java.lang.String componentFromPoint(
        int x,
        int y);

    @DISPID(-2147417069)
    void doScroll(
        java.lang.Object component);

    @DISPID(-2147412081)
    @PropPut
    void onscroll(
        java.lang.Object rhs);

    @DISPID(-2147412081)
    @PropGet
    java.lang.Object onscroll();

    @DISPID(-2147412063)
    @PropPut
    void ondrag(
        java.lang.Object rhs);

    @DISPID(-2147412063)
    @PropGet
    java.lang.Object ondrag();

    @DISPID(-2147412062)
    @PropPut
    void ondragend(
        java.lang.Object rhs);

    @DISPID(-2147412062)
    @PropGet
    java.lang.Object ondragend();

    @DISPID(-2147412061)
    @PropPut
    void ondragenter(
        java.lang.Object rhs);

    @DISPID(-2147412061)
    @PropGet
    java.lang.Object ondragenter();

    @DISPID(-2147412060)
    @PropPut
    void ondragover(
        java.lang.Object rhs);

    @DISPID(-2147412060)
    @PropGet
    java.lang.Object ondragover();

    @DISPID(-2147412059)
    @PropPut
    void ondragleave(
        java.lang.Object rhs);

    @DISPID(-2147412059)
    @PropGet
    java.lang.Object ondragleave();

    @DISPID(-2147412058)
    @PropPut
    void ondrop(
        java.lang.Object rhs);

    @DISPID(-2147412058)
    @PropGet
    java.lang.Object ondrop();

    @DISPID(-2147412054)
    @PropPut
    void onbeforecut(
        java.lang.Object rhs);

    @DISPID(-2147412054)
    @PropGet
    java.lang.Object onbeforecut();

    @DISPID(-2147412057)
    @PropPut
    void oncut(
        java.lang.Object rhs);

    @DISPID(-2147412057)
    @PropGet
    java.lang.Object oncut();

    @DISPID(-2147412053)
    @PropPut
    void onbeforecopy(
        java.lang.Object rhs);

    @DISPID(-2147412053)
    @PropGet
    java.lang.Object onbeforecopy();

    @DISPID(-2147412056)
    @PropPut
    void oncopy(
        java.lang.Object rhs);

    @DISPID(-2147412056)
    @PropGet
    java.lang.Object oncopy();

    @DISPID(-2147412052)
    @PropPut
    void onbeforepaste(
        java.lang.Object rhs);

    @DISPID(-2147412052)
    @PropGet
    java.lang.Object onbeforepaste();

    @DISPID(-2147412055)
    @PropPut
    void onpaste(
        java.lang.Object rhs);

    @DISPID(-2147412055)
    @PropGet
    java.lang.Object onpaste();

    @DISPID(-2147417105)
    @PropGet
    mol.mshtml.IHTMLCurrentStyle currentStyle();

    @DISPID(-2147412065)
    @PropPut
    void onpropertychange(
        java.lang.Object rhs);

    @DISPID(-2147412065)
    @PropGet
    java.lang.Object onpropertychange();

    @DISPID(-2147417068)
    mol.mshtml.IHTMLRectCollection getClientRects();

    @DISPID(-2147417067)
    mol.mshtml.IHTMLRect getBoundingClientRect();

    @DISPID(-2147417608)
    void setExpression(
        java.lang.String propname,
        java.lang.String expression,
        java.lang.String language);

    @DISPID(-2147417607)
    java.lang.Object getExpression(
        java.lang.String propname);

    @DISPID(-2147417606)
    boolean removeExpression(
        java.lang.String propname);

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

    @DISPID(-2147417605)
    boolean attachEvent(
        java.lang.String event,
        com4j.Com4jObject pdisp);

    @DISPID(-2147417604)
    void detachEvent(
        java.lang.String event,
        com4j.Com4jObject pdisp);

    @DISPID(-2147412996)
    @PropGet
    java.lang.Object readyState();

    @DISPID(-2147412087)
    @PropPut
    void onreadystatechange(
        java.lang.Object rhs);

    @DISPID(-2147412087)
    @PropGet
    java.lang.Object onreadystatechange();

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

    @DISPID(-2147412995)
    @PropPut
    void dir(
        java.lang.String rhs);

    @DISPID(-2147412995)
    @PropGet
    java.lang.String dir();

    @DISPID(-2147417056)
    com4j.Com4jObject createControlRange();

    @DISPID(-2147417055)
    @PropGet
    int scrollHeight();

    @DISPID(-2147417054)
    @PropGet
    int scrollWidth();

    @DISPID(-2147417053)
    @PropPut
    void scrollTop(
        int rhs);

    @DISPID(-2147417053)
    @PropGet
    int scrollTop();

    @DISPID(-2147417052)
    @PropPut
    void scrollLeft(
        int rhs);

    @DISPID(-2147417052)
    @PropGet
    int scrollLeft();

    @DISPID(-2147417050)
    void clearAttributes();

    @DISPID(-2147412047)
    @PropPut
    void oncontextmenu(
        java.lang.Object rhs);

    @DISPID(-2147412047)
    @PropGet
    java.lang.Object oncontextmenu();

    @DISPID(-2147417043)
    mol.mshtml.IHTMLElement insertAdjacentElement(
        java.lang.String where,
        mol.mshtml.IHTMLElement insertedElement);

    @DISPID(-2147417047)
    mol.mshtml.IHTMLElement applyElement(
        mol.mshtml.IHTMLElement apply,
        java.lang.String where);

    @DISPID(-2147417042)
    java.lang.String getAdjacentText(
        java.lang.String where);

    @DISPID(-2147417041)
    java.lang.String replaceAdjacentText(
        java.lang.String where,
        java.lang.String newText);

    @DISPID(-2147417040)
    @PropGet
    boolean canHaveChildren();

    @DISPID(-2147417032)
    int addBehavior(
        java.lang.String bstrUrl,
        java.lang.Object pvarFactory);

    @DISPID(-2147417031)
    boolean removeBehavior(
        int cookie);

    @DISPID(-2147417048)
    @PropGet
    mol.mshtml.IHTMLStyle runtimeStyle();

    @DISPID(-2147417030)
    @PropGet
    com4j.Com4jObject behaviorUrns();

    @DISPID(-2147417029)
    @PropPut
    void tagUrn(
        java.lang.String rhs);

    @DISPID(-2147417029)
    @PropGet
    java.lang.String tagUrn();

    @DISPID(-2147412043)
    @PropPut
    void onbeforeeditfocus(
        java.lang.Object rhs);

    @DISPID(-2147412043)
    @PropGet
    java.lang.Object onbeforeeditfocus();

    @DISPID(-2147417028)
    @PropGet
    int readyStateValue();

    @DISPID(-2147417027)
    mol.mshtml.IHTMLElementCollection getElementsByTagName(
        java.lang.String v);

    @DISPID(-2147417016)
    void mergeAttributes(
        mol.mshtml.IHTMLElement mergeThis,
        java.lang.Object pvarFlags);

    @DISPID(-2147417015)
    @PropGet
    boolean isMultiLine();

    @DISPID(-2147417014)
    @PropGet
    boolean canHaveHTML();

    @DISPID(-2147412039)
    @PropPut
    void onlayoutcomplete(
        java.lang.Object rhs);

    @DISPID(-2147412039)
    @PropGet
    java.lang.Object onlayoutcomplete();

    @DISPID(-2147412038)
    @PropPut
    void onpage(
        java.lang.Object rhs);

    @DISPID(-2147412038)
    @PropGet
    java.lang.Object onpage();

    @DISPID(-2147417012)
    @PropPut
    void inflateBlock(
        boolean rhs);

    @DISPID(-2147417012)
    @PropGet
    boolean inflateBlock();

    @DISPID(-2147412035)
    @PropPut
    void onbeforedeactivate(
        java.lang.Object rhs);

    @DISPID(-2147412035)
    @PropGet
    java.lang.Object onbeforedeactivate();

    @DISPID(-2147417011)
    void setActive();

    @DISPID(-2147412950)
    @PropPut
    void contentEditable(
        java.lang.String rhs);

    @DISPID(-2147412950)
    @PropGet
    java.lang.String contentEditable();

    @DISPID(-2147417010)
    @PropGet
    boolean isContentEditable();

    @DISPID(-2147412949)
    @PropPut
    void hideFocus(
        boolean rhs);

    @DISPID(-2147412949)
    @PropGet
    boolean hideFocus();

    @DISPID(-2147418036)
    @PropPut
    void disabled(
        boolean rhs);

    @DISPID(-2147418036)
    @PropGet
    boolean disabled();

    @DISPID(-2147417007)
    @PropGet
    boolean isDisabled();

    @DISPID(-2147412034)
    @PropPut
    void onmove(
        java.lang.Object rhs);

    @DISPID(-2147412034)
    @PropGet
    java.lang.Object onmove();

    @DISPID(-2147412033)
    @PropPut
    void oncontrolselect(
        java.lang.Object rhs);

    @DISPID(-2147412033)
    @PropGet
    java.lang.Object oncontrolselect();

    @DISPID(-2147417006)
    boolean fireEvent(
        java.lang.String bstrEventName,
        java.lang.Object pvarEventObject);

    @DISPID(-2147412029)
    @PropPut
    void onresizestart(
        java.lang.Object rhs);

    @DISPID(-2147412029)
    @PropGet
    java.lang.Object onresizestart();

    @DISPID(-2147412028)
    @PropPut
    void onresizeend(
        java.lang.Object rhs);

    @DISPID(-2147412028)
    @PropGet
    java.lang.Object onresizeend();

    @DISPID(-2147412031)
    @PropPut
    void onmovestart(
        java.lang.Object rhs);

    @DISPID(-2147412031)
    @PropGet
    java.lang.Object onmovestart();

    @DISPID(-2147412030)
    @PropPut
    void onmoveend(
        java.lang.Object rhs);

    @DISPID(-2147412030)
    @PropGet
    java.lang.Object onmoveend();

    @DISPID(-2147412027)
    @PropPut
    void onmouseenter(
        java.lang.Object rhs);

    @DISPID(-2147412027)
    @PropGet
    java.lang.Object onmouseenter();

    @DISPID(-2147412026)
    @PropPut
    void onmouseleave(
        java.lang.Object rhs);

    @DISPID(-2147412026)
    @PropGet
    java.lang.Object onmouseleave();

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

    @DISPID(-2147417005)
    boolean dragDrop();

    @DISPID(-2147417004)
    @PropGet
    int glyphMode();

    @DISPID(-2147412036)
    @PropPut
    void onmousewheel(
        java.lang.Object rhs);

    @DISPID(-2147412036)
    @PropGet
    java.lang.Object onmousewheel();

    @DISPID(-2147417000)
    void normalize();

    @DISPID(-2147417003)
    mol.mshtml.IHTMLDOMAttribute getAttributeNode(
        java.lang.String bstrName);

    @DISPID(-2147417002)
    mol.mshtml.IHTMLDOMAttribute setAttributeNode(
        mol.mshtml.IHTMLDOMAttribute pattr);

    @DISPID(-2147417001)
    mol.mshtml.IHTMLDOMAttribute removeAttributeNode(
        mol.mshtml.IHTMLDOMAttribute pattr);

    @DISPID(-2147412022)
    @PropPut
    void onbeforeactivate(
        java.lang.Object rhs);

    @DISPID(-2147412022)
    @PropGet
    java.lang.Object onbeforeactivate();

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

    @DISPID(-2147417058)
    @PropGet
    int uniqueNumber();

    @DISPID(-2147417057)
    @PropGet
    java.lang.String uniqueID();

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

    @DISPID(-2147413111)
    @PropPut
    void background(
        java.lang.String rhs);

    @DISPID(-2147413111)
    @PropGet
    java.lang.String background();

    @DISPID(-2147413067)
    @PropPut
    void bgProperties(
        java.lang.String rhs);

    @DISPID(-2147413067)
    @PropGet
    java.lang.String bgProperties();

    @DISPID(-2147413072)
    @PropPut
    void leftMargin(
        java.lang.Object rhs);

    @DISPID(-2147413072)
    @PropGet
    java.lang.Object leftMargin();

    @DISPID(-2147413075)
    @PropPut
    void topMargin(
        java.lang.Object rhs);

    @DISPID(-2147413075)
    @PropGet
    java.lang.Object topMargin();

    @DISPID(-2147413074)
    @PropPut
    void rightMargin(
        java.lang.Object rhs);

    @DISPID(-2147413074)
    @PropGet
    java.lang.Object rightMargin();

    @DISPID(-2147413073)
    @PropPut
    void bottomMargin(
        java.lang.Object rhs);

    @DISPID(-2147413073)
    @PropGet
    java.lang.Object bottomMargin();

    @DISPID(-2147413107)
    @PropPut
    void noWrap(
        boolean rhs);

    @DISPID(-2147413107)
    @PropGet
    boolean noWrap();

    @DISPID(-501)
    @PropPut
    void bgColor(
        java.lang.Object rhs);

    @DISPID(-501)
    @PropGet
    java.lang.Object bgColor();

    @DISPID(-2147413110)
    @PropPut
    void text(
        java.lang.Object rhs);

    @DISPID(-2147413110)
    @PropGet
    java.lang.Object text();

    @DISPID(2010)
    @PropPut
    void link(
        java.lang.Object rhs);

    @DISPID(2010)
    @PropGet
    java.lang.Object link();

    @DISPID(2012)
    @PropPut
    void vLink(
        java.lang.Object rhs);

    @DISPID(2012)
    @PropGet
    java.lang.Object vLink();

    @DISPID(2011)
    @PropPut
    void aLink(
        java.lang.Object rhs);

    @DISPID(2011)
    @PropGet
    java.lang.Object aLink();

    @DISPID(-2147412080)
    @PropPut
    void onload(
        java.lang.Object rhs);

    @DISPID(-2147412080)
    @PropGet
    java.lang.Object onload();

    @DISPID(-2147412079)
    @PropPut
    void onunload(
        java.lang.Object rhs);

    @DISPID(-2147412079)
    @PropGet
    java.lang.Object onunload();

    @DISPID(-2147413033)
    @PropPut
    void scroll(
        java.lang.String rhs);

    @DISPID(-2147413033)
    @PropGet
    java.lang.String scroll();

    @DISPID(-2147412102)
    @PropPut
    void onselect(
        java.lang.Object rhs);

    @DISPID(-2147412102)
    @PropGet
    java.lang.Object onselect();

    @DISPID(-2147412073)
    @PropPut
    void onbeforeunload(
        java.lang.Object rhs);

    @DISPID(-2147412073)
    @PropGet
    java.lang.Object onbeforeunload();

    @DISPID(2013)
    mol.mshtml.IHTMLTxtRange createTextRange();

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

}
