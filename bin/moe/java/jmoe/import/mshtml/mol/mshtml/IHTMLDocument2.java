package mol.mshtml  ;

import com4j.*;

@IID("{332C4425-26CB-11D0-B483-00C04FD90119}")
public interface IHTMLDocument2 extends mol.mshtml.IHTMLDocument {
    @VTID(8)
    mol.mshtml.IHTMLElementCollection all();

    @VTID(8)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject all(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(9)
    mol.mshtml.IHTMLElement body();

    @VTID(10)
    mol.mshtml.IHTMLElement activeElement();

    @VTID(11)
    mol.mshtml.IHTMLElementCollection images();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject images(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    mol.mshtml.IHTMLElementCollection applets();

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject applets(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    mol.mshtml.IHTMLElementCollection links();

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject links(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    mol.mshtml.IHTMLElementCollection forms();

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject forms(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(15)
    mol.mshtml.IHTMLElementCollection anchors();

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject anchors(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(16)
    void title(
        java.lang.String p);

    @VTID(17)
    java.lang.String title();

    @VTID(18)
    mol.mshtml.IHTMLElementCollection scripts();

    @VTID(18)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject scripts(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(19)
    void designMode(
        java.lang.String p);

    @VTID(20)
    java.lang.String designMode();

    @VTID(21)
    mol.mshtml.IHTMLSelectionObject selection();

    @VTID(22)
    java.lang.String readyState();

    @VTID(23)
    mol.mshtml.IHTMLFramesCollection2 frames();

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT,defaultPropertyThrough={mol.mshtml.IHTMLFramesCollection2.class})
    java.lang.Object frames(
        java.lang.Object pvarIndex);

    @VTID(24)
    mol.mshtml.IHTMLElementCollection embeds();

    @VTID(24)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject embeds(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(25)
    mol.mshtml.IHTMLElementCollection plugins();

    @VTID(25)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject plugins(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(26)
    void alinkColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(27)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object alinkColor();

    @VTID(28)
    void bgColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(29)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bgColor();

    @VTID(30)
    void fgColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(31)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object fgColor();

    @VTID(32)
    void linkColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(33)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object linkColor();

    @VTID(34)
    void vlinkColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object vlinkColor();

    @VTID(36)
    java.lang.String referrer();

    @VTID(37)
    mol.mshtml.IHTMLLocation location();

    @VTID(38)
    java.lang.String lastModified();

    @VTID(39)
    void url(
        java.lang.String p);

    @VTID(40)
    java.lang.String url();

    @VTID(41)
    void domain(
        java.lang.String p);

    @VTID(42)
    java.lang.String domain();

    @VTID(43)
    void cookie(
        java.lang.String p);

    @VTID(44)
    java.lang.String cookie();

    @VTID(45)
    void expando(
        boolean p);

    @VTID(46)
    boolean expando();

    @VTID(47)
    void charset(
        java.lang.String p);

    @VTID(48)
    java.lang.String charset();

    @VTID(49)
    void defaultCharset(
        java.lang.String p);

    @VTID(50)
    java.lang.String defaultCharset();

    @VTID(51)
    java.lang.String mimeType();

    @VTID(52)
    java.lang.String fileSize();

    @VTID(53)
    java.lang.String fileCreatedDate();

    @VTID(54)
    java.lang.String fileModifiedDate();

    @VTID(55)
    java.lang.String fileUpdatedDate();

    @VTID(56)
    java.lang.String security();

    @VTID(57)
    java.lang.String protocol();

    @VTID(58)
    java.lang.String nameProp();

    @VTID(59)
    void write(
        java.lang.Object... psarray);

    @VTID(60)
    void writeln(
        java.lang.Object... psarray);

    @VTID(61)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject open(
        java.lang.String url,
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object features,
        @MarshalAs(NativeType.VARIANT) java.lang.Object replace);

    @VTID(62)
    void close();

    @VTID(63)
    void clear();

    @VTID(64)
    boolean queryCommandSupported(
        java.lang.String cmdID);

    @VTID(65)
    boolean queryCommandEnabled(
        java.lang.String cmdID);

    @VTID(66)
    boolean queryCommandState(
        java.lang.String cmdID);

    @VTID(67)
    boolean queryCommandIndeterm(
        java.lang.String cmdID);

    @VTID(68)
    java.lang.String queryCommandText(
        java.lang.String cmdID);

    @VTID(69)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object queryCommandValue(
        java.lang.String cmdID);

    @VTID(70)
    boolean execCommand(
        java.lang.String cmdID,
        boolean showUI,
        @MarshalAs(NativeType.VARIANT) java.lang.Object value);

    @VTID(71)
    boolean execCommandShowHelp(
        java.lang.String cmdID);

    @VTID(72)
    mol.mshtml.IHTMLElement createElement(
        java.lang.String eTag);

    @VTID(73)
    void onhelp(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(74)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onhelp();

    @VTID(75)
    void onclick(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(76)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onclick();

    @VTID(77)
    void ondblclick(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(78)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondblclick();

    @VTID(79)
    void onkeyup(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(80)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onkeyup();

    @VTID(81)
    void onkeydown(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(82)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onkeydown();

    @VTID(83)
    void onkeypress(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(84)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onkeypress();

    @VTID(85)
    void onmouseup(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(86)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmouseup();

    @VTID(87)
    void onmousedown(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(88)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmousedown();

    @VTID(89)
    void onmousemove(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(90)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmousemove();

    @VTID(91)
    void onmouseout(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(92)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmouseout();

    @VTID(93)
    void onmouseover(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(94)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onmouseover();

    @VTID(95)
    void onreadystatechange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(96)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onreadystatechange();

    @VTID(97)
    void onafterupdate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(98)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onafterupdate();

    @VTID(99)
    void onrowexit(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(100)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onrowexit();

    @VTID(101)
    void onrowenter(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(102)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onrowenter();

    @VTID(103)
    void ondragstart(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(104)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ondragstart();

    @VTID(105)
    void onselectstart(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(106)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onselectstart();

    @VTID(107)
    mol.mshtml.IHTMLElement elementFromPoint(
        int x,
        int y);

    @VTID(108)
    mol.mshtml.IHTMLWindow2 parentWindow();

    @VTID(109)
    mol.mshtml.IHTMLStyleSheetsCollection styleSheets();

    @VTID(109)
    @ReturnValue(type=NativeType.VARIANT,defaultPropertyThrough={mol.mshtml.IHTMLStyleSheetsCollection.class})
    java.lang.Object styleSheets(
        java.lang.Object pvarIndex);

    @VTID(110)
    void onbeforeupdate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(111)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforeupdate();

    @VTID(112)
    void onerrorupdate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(113)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onerrorupdate();

    @VTID(114)
    java.lang.String toString_();

    @VTID(115)
    mol.mshtml.IHTMLStyleSheet createStyleSheet(
        java.lang.String bstrHref,
        int lIndex);

}
