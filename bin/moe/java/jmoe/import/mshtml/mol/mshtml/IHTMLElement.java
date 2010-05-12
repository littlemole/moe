package mol.mshtml  ;

import com4j.*;

@IID("{3050F1FF-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLElement extends Com4jObject {
    @VTID(7)
    void setAttribute(
        java.lang.String strAttributeName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object attributeValue,
        int lFlags);

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object getAttribute(
        java.lang.String strAttributeName,
        int lFlags);

    @VTID(9)
    boolean removeAttribute(
        java.lang.String strAttributeName,
        int lFlags);

    @VTID(10)
    void className(
        java.lang.String p);

    @VTID(11)
    java.lang.String className();

    @VTID(12)
    void id(
        java.lang.String p);

    @VTID(13)
    java.lang.String id();

    @VTID(14)
    java.lang.String tagName();

    @VTID(15)
    mol.mshtml.IHTMLElement parentElement();

    @VTID(16)
    mol.mshtml.IHTMLStyle style();

    @VTID(17)
    void onhelp(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onhelp();

    @VTID(19)
    void onclick(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onclick();

    @VTID(21)
    void ondblclick(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondblclick();

    @VTID(23)
    void onkeydown(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onkeydown();

    @VTID(25)
    void onkeyup(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onkeyup();

    @VTID(27)
    void onkeypress(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onkeypress();

    @VTID(29)
    void onmouseout(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmouseout();

    @VTID(31)
    void onmouseover(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(32)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmouseover();

    @VTID(33)
    void onmousemove(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmousemove();

    @VTID(35)
    void onmousedown(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(36)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmousedown();

    @VTID(37)
    void onmouseup(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(38)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmouseup();

    @VTID(39)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject document();

    @VTID(40)
    void title(
        java.lang.String p);

    @VTID(41)
    java.lang.String title();

    @VTID(42)
    void language(
        java.lang.String p);

    @VTID(43)
    java.lang.String language();

    @VTID(44)
    void onselectstart(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(45)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onselectstart();

    @VTID(46)
    void scrollIntoView(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varargStart);

    @VTID(47)
    boolean contains(
        mol.mshtml.IHTMLElement pChild);

    @VTID(48)
    int sourceIndex();

    @VTID(49)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object recordNumber();

    @VTID(50)
    void lang(
        java.lang.String p);

    @VTID(51)
    java.lang.String lang();

    @VTID(52)
    int offsetLeft();

    @VTID(53)
    int offsetTop();

    @VTID(54)
    int offsetWidth();

    @VTID(55)
    int offsetHeight();

    @VTID(56)
    mol.mshtml.IHTMLElement offsetParent();

    @VTID(57)
    void innerHTML(
        java.lang.String p);

    @VTID(58)
    java.lang.String innerHTML();

    @VTID(59)
    void innerText(
        java.lang.String p);

    @VTID(60)
    java.lang.String innerText();

    @VTID(61)
    void outerHTML(
        java.lang.String p);

    @VTID(62)
    java.lang.String outerHTML();

    @VTID(63)
    void outerText(
        java.lang.String p);

    @VTID(64)
    java.lang.String outerText();

    @VTID(65)
    void insertAdjacentHTML(
        java.lang.String where,
        java.lang.String html);

    @VTID(66)
    void insertAdjacentText(
        java.lang.String where,
        java.lang.String text);

    @VTID(67)
    mol.mshtml.IHTMLElement parentTextEdit();

    @VTID(68)
    boolean isTextEdit();

    @VTID(69)
    void click();

    @VTID(70)
    mol.mshtml.IHTMLFiltersCollection filters();

    @VTID(70)
    @ReturnValue(type=NativeType.VARIANT,defaultPropertyThrough={mol.mshtml.IHTMLFiltersCollection.class})
    java.lang.Object filters(
        java.lang.Object pvarIndex);

    @VTID(71)
    void ondragstart(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(72)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondragstart();

    @VTID(73)
    java.lang.String toString_();

    @VTID(74)
    void onbeforeupdate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(75)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforeupdate();

    @VTID(76)
    void onafterupdate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(77)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onafterupdate();

    @VTID(78)
    void onerrorupdate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(79)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onerrorupdate();

    @VTID(80)
    void onrowexit(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(81)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onrowexit();

    @VTID(82)
    void onrowenter(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(83)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onrowenter();

    @VTID(84)
    void ondatasetchanged(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(85)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondatasetchanged();

    @VTID(86)
    void ondataavailable(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(87)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondataavailable();

    @VTID(88)
    void ondatasetcomplete(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(89)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondatasetcomplete();

    @VTID(90)
    void onfilterchange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(91)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onfilterchange();

    @VTID(92)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject children();

    @VTID(93)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject all();

}
