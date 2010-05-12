package mol.mshtml  ;

import com4j.*;

@IID("{3050F434-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLElement2 extends Com4jObject {
    @VTID(7)
    java.lang.String scopeName();

    @VTID(8)
    void setCapture(
        boolean containerCapture);

    @VTID(9)
    void releaseCapture();

    @VTID(10)
    void onlosecapture(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onlosecapture();

    @VTID(12)
    java.lang.String componentFromPoint(
        int x,
        int y);

    @VTID(13)
    void doScroll(
        @MarshalAs(NativeType.VARIANT) java.lang.Object component);

    @VTID(14)
    void onscroll(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onscroll();

    @VTID(16)
    void ondrag(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondrag();

    @VTID(18)
    void ondragend(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondragend();

    @VTID(20)
    void ondragenter(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondragenter();

    @VTID(22)
    void ondragover(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondragover();

    @VTID(24)
    void ondragleave(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(25)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondragleave();

    @VTID(26)
    void ondrop(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(27)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondrop();

    @VTID(28)
    void onbeforecut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(29)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforecut();

    @VTID(30)
    void oncut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(31)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object oncut();

    @VTID(32)
    void onbeforecopy(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(33)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforecopy();

    @VTID(34)
    void oncopy(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object oncopy();

    @VTID(36)
    void onbeforepaste(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(37)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforepaste();

    @VTID(38)
    void onpaste(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(39)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onpaste();

    @VTID(40)
    mol.mshtml.IHTMLCurrentStyle currentStyle();

    @VTID(41)
    void onpropertychange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(42)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onpropertychange();

    @VTID(43)
    mol.mshtml.IHTMLRectCollection getClientRects();

    @VTID(43)
    @ReturnValue(type=NativeType.VARIANT,defaultPropertyThrough={mol.mshtml.IHTMLRectCollection.class})
    java.lang.Object getClientRects(
        java.lang.Object pvarIndex);

    @VTID(44)
    mol.mshtml.IHTMLRect getBoundingClientRect();

    @VTID(45)
    void setExpression(
        java.lang.String propname,
        java.lang.String expression,
        java.lang.String language);

    @VTID(46)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object getExpression(
        java.lang.String propname);

    @VTID(47)
    boolean removeExpression(
        java.lang.String propname);

    @VTID(48)
    void tabIndex(
        short p);

    @VTID(49)
    short tabIndex();

    @VTID(50)
    void focus();

    @VTID(51)
    void accessKey(
        java.lang.String p);

    @VTID(52)
    java.lang.String accessKey();

    @VTID(53)
    void onblur(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(54)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onblur();

    @VTID(55)
    void onfocus(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(56)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onfocus();

    @VTID(57)
    void onresize(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(58)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onresize();

    @VTID(59)
    void blur();

    @VTID(60)
    void addFilter(
        com4j.Com4jObject pUnk);

    @VTID(61)
    void removeFilter(
        com4j.Com4jObject pUnk);

    @VTID(62)
    int clientHeight();

    @VTID(63)
    int clientWidth();

    @VTID(64)
    int clientTop();

    @VTID(65)
    int clientLeft();

    @VTID(66)
    boolean attachEvent(
        java.lang.String event,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pdisp);

    @VTID(67)
    void detachEvent(
        java.lang.String event,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pdisp);

    @VTID(68)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object readyState();

    @VTID(69)
    void onreadystatechange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(70)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onreadystatechange();

    @VTID(71)
    void onrowsdelete(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(72)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onrowsdelete();

    @VTID(73)
    void onrowsinserted(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(74)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onrowsinserted();

    @VTID(75)
    void oncellchange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(76)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object oncellchange();

    @VTID(77)
    void dir(
        java.lang.String p);

    @VTID(78)
    java.lang.String dir();

    @VTID(79)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject createControlRange();

    @VTID(80)
    int scrollHeight();

    @VTID(81)
    int scrollWidth();

    @VTID(82)
    void scrollTop(
        int p);

    @VTID(83)
    int scrollTop();

    @VTID(84)
    void scrollLeft(
        int p);

    @VTID(85)
    int scrollLeft();

    @VTID(86)
    void clearAttributes();

    @VTID(87)
    void mergeAttributes(
        mol.mshtml.IHTMLElement mergeThis);

    @VTID(88)
    void oncontextmenu(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(89)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object oncontextmenu();

    @VTID(90)
    mol.mshtml.IHTMLElement insertAdjacentElement(
        java.lang.String where,
        mol.mshtml.IHTMLElement insertedElement);

    @VTID(91)
    mol.mshtml.IHTMLElement applyElement(
        mol.mshtml.IHTMLElement apply,
        java.lang.String where);

    @VTID(92)
    java.lang.String getAdjacentText(
        java.lang.String where);

    @VTID(93)
    java.lang.String replaceAdjacentText(
        java.lang.String where,
        java.lang.String newText);

    @VTID(94)
    boolean canHaveChildren();

    @VTID(95)
    int addBehavior(
        java.lang.String bstrUrl,
        java.lang.Object pvarFactory);

    @VTID(96)
    boolean removeBehavior(
        int cookie);

    @VTID(97)
    mol.mshtml.IHTMLStyle runtimeStyle();

    @VTID(98)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject behaviorUrns();

    @VTID(99)
    void tagUrn(
        java.lang.String p);

    @VTID(100)
    java.lang.String tagUrn();

    @VTID(101)
    void onbeforeeditfocus(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(102)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforeeditfocus();

    @VTID(103)
    int readyStateValue();

    @VTID(104)
    mol.mshtml.IHTMLElementCollection getElementsByTagName(
        java.lang.String v);

}
