package mol.mshtml  ;

import com4j.*;

@IID("{332C4427-26CB-11D0-B483-00C04FD90119}")
public interface IHTMLWindow2 extends mol.mshtml.IHTMLFramesCollection2 {
    @VTID(9)
    mol.mshtml.IHTMLFramesCollection2 frames();

    @VTID(9)
    @ReturnValue(type=NativeType.VARIANT,defaultPropertyThrough={mol.mshtml.IHTMLFramesCollection2.class})
    java.lang.Object frames(
        java.lang.Object pvarIndex);

    @VTID(10)
    void defaultStatus(
        java.lang.String p);

    @VTID(11)
    java.lang.String defaultStatus();

    @VTID(12)
    void status(
        java.lang.String p);

    @VTID(13)
    java.lang.String status();

    @VTID(14)
    int setTimeout(
        java.lang.String expression,
        int msec,
        java.lang.Object language);

    @VTID(15)
    void clearTimeout(
        int timerID);

    @VTID(16)
    void alert(
        java.lang.String message);

    @VTID(17)
    boolean confirm(
        java.lang.String message);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object prompt(
        java.lang.String message,
        java.lang.String defstr);

    @VTID(19)
    mol.mshtml.IHTMLImageElementFactory image();

    @VTID(19)
    @ReturnValue(defaultPropertyThrough={mol.mshtml.IHTMLImageElementFactory.class})
    mol.mshtml.IHTMLImgElement image(
        @MarshalAs(NativeType.VARIANT) java.lang.Object width,
        @MarshalAs(NativeType.VARIANT) java.lang.Object height);

    @VTID(20)
    mol.mshtml.IHTMLLocation location();

    @VTID(21)
    mol.mshtml.IOmHistory history();

    @VTID(22)
    void close();

    @VTID(23)
    void opener(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object opener();

    @VTID(25)
    mol.mshtml.IOmNavigator navigator();

    @VTID(26)
    void name(
        java.lang.String p);

    @VTID(27)
    java.lang.String name();

    @VTID(28)
    mol.mshtml.IHTMLWindow2 parent();

    @VTID(29)
    mol.mshtml.IHTMLWindow2 open(
        java.lang.String url,
        java.lang.String name,
        java.lang.String features,
        boolean replace);

    @VTID(30)
    mol.mshtml.IHTMLWindow2 self();

    @VTID(31)
    mol.mshtml.IHTMLWindow2 top();

    @VTID(32)
    mol.mshtml.IHTMLWindow2 window();

    @VTID(33)
    void navigate(
        java.lang.String url);

    @VTID(34)
    void onfocus(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onfocus();

    @VTID(36)
    void onblur(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(37)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onblur();

    @VTID(38)
    void onload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(39)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onload();

    @VTID(40)
    void onbeforeunload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(41)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforeunload();

    @VTID(42)
    void onunload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(43)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onunload();

    @VTID(44)
    void onhelp(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(45)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onhelp();

    @VTID(46)
    void onerror(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(47)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onerror();

    @VTID(48)
    void onresize(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(49)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onresize();

    @VTID(50)
    void onscroll(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(51)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onscroll();

    @VTID(52)
    mol.mshtml.IHTMLDocument2 document();

    @VTID(53)
    mol.mshtml.IHTMLEventObj event();

    @VTID(54)
    com4j.Com4jObject _newEnum();

    @VTID(55)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object showModalDialog(
        java.lang.String dialog,
        java.lang.Object varArgIn,
        java.lang.Object varOptions);

    @VTID(56)
    void showHelp(
        java.lang.String helpURL,
        @MarshalAs(NativeType.VARIANT) java.lang.Object helpArg,
        java.lang.String features);

    @VTID(57)
    mol.mshtml.IHTMLScreen screen();

    @VTID(58)
    mol.mshtml.IHTMLOptionElementFactory option();

    @VTID(58)
    @ReturnValue(defaultPropertyThrough={mol.mshtml.IHTMLOptionElementFactory.class})
    mol.mshtml.IHTMLOptionElement option(
        @MarshalAs(NativeType.VARIANT) java.lang.Object text,
        @MarshalAs(NativeType.VARIANT) java.lang.Object value,
        @MarshalAs(NativeType.VARIANT) java.lang.Object defaultSelected,
        @MarshalAs(NativeType.VARIANT) java.lang.Object selected);

    @VTID(59)
    void focus();

    @VTID(60)
    boolean closed();

    @VTID(61)
    void blur();

    @VTID(62)
    void scroll(
        int x,
        int y);

    @VTID(63)
    mol.mshtml.IOmNavigator clientInformation();

    @VTID(64)
    int setInterval(
        java.lang.String expression,
        int msec,
        java.lang.Object language);

    @VTID(65)
    void clearInterval(
        int timerID);

    @VTID(66)
    void offscreenBuffering(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(67)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object offscreenBuffering();

    @VTID(68)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object execScript(
        java.lang.String code,
        java.lang.String language);

    @VTID(69)
    java.lang.String toString_();

    @VTID(70)
    void scrollBy(
        int x,
        int y);

    @VTID(71)
    void scrollTo(
        int x,
        int y);

    @VTID(72)
    void moveTo(
        int x,
        int y);

    @VTID(73)
    void moveBy(
        int x,
        int y);

    @VTID(74)
    void resizeTo(
        int x,
        int y);

    @VTID(75)
    void resizeBy(
        int x,
        int y);

    @VTID(76)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject external();

}
