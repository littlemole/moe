package mol.mshtml  ;

import com4j.*;

@IID("{3050F48B-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLEventObj2 extends Com4jObject {
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
    void propertyName(
        java.lang.String p);

    @VTID(11)
    java.lang.String propertyName();

    @VTID(12)
    void bookmarks(
        mol.mshtml.IHTMLBookmarkCollection p);

    @VTID(13)
    mol.mshtml.IHTMLBookmarkCollection bookmarks();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT,defaultPropertyThrough={mol.mshtml.IHTMLBookmarkCollection.class})
    java.lang.Object bookmarks(
        int index);

    @VTID(14)
    void recordset(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject p);

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject recordset();

    @VTID(16)
    void dataFld(
        java.lang.String p);

    @VTID(17)
    java.lang.String dataFld();

    @VTID(18)
    void boundElements(
        mol.mshtml.IHTMLElementCollection p);

    @VTID(19)
    mol.mshtml.IHTMLElementCollection boundElements();

    @VTID(19)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject boundElements(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(20)
    void repeat(
        boolean p);

    @VTID(21)
    boolean repeat();

    @VTID(22)
    void srcUrn(
        java.lang.String p);

    @VTID(23)
    java.lang.String srcUrn();

    @VTID(24)
    void srcElement(
        mol.mshtml.IHTMLElement p);

    @VTID(25)
    mol.mshtml.IHTMLElement srcElement();

    @VTID(26)
    void altKey(
        boolean p);

    @VTID(27)
    boolean altKey();

    @VTID(28)
    void ctrlKey(
        boolean p);

    @VTID(29)
    boolean ctrlKey();

    @VTID(30)
    void shiftKey(
        boolean p);

    @VTID(31)
    boolean shiftKey();

    @VTID(32)
    void fromElement(
        mol.mshtml.IHTMLElement p);

    @VTID(33)
    mol.mshtml.IHTMLElement fromElement();

    @VTID(34)
    void toElement(
        mol.mshtml.IHTMLElement p);

    @VTID(35)
    mol.mshtml.IHTMLElement toElement();

    @VTID(36)
    void button(
        int p);

    @VTID(37)
    int button();

    @VTID(38)
    void type(
        java.lang.String p);

    @VTID(39)
    java.lang.String type();

    @VTID(40)
    void qualifier(
        java.lang.String p);

    @VTID(41)
    java.lang.String qualifier();

    @VTID(42)
    void reason(
        int p);

    @VTID(43)
    int reason();

    @VTID(44)
    void x(
        int p);

    @VTID(45)
    int x();

    @VTID(46)
    void y(
        int p);

    @VTID(47)
    int y();

    @VTID(48)
    void clientX(
        int p);

    @VTID(49)
    int clientX();

    @VTID(50)
    void clientY(
        int p);

    @VTID(51)
    int clientY();

    @VTID(52)
    void offsetX(
        int p);

    @VTID(53)
    int offsetX();

    @VTID(54)
    void offsetY(
        int p);

    @VTID(55)
    int offsetY();

    @VTID(56)
    void screenX(
        int p);

    @VTID(57)
    int screenX();

    @VTID(58)
    void screenY(
        int p);

    @VTID(59)
    int screenY();

    @VTID(60)
    void srcFilter(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject p);

    @VTID(61)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject srcFilter();

    @VTID(62)
    mol.mshtml.IHTMLDataTransfer dataTransfer();

}
