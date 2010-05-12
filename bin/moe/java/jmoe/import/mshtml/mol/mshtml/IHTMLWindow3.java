package mol.mshtml  ;

import com4j.*;

@IID("{3050F4AE-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLWindow3 extends Com4jObject {
    @VTID(7)
    int screenLeft();

    @VTID(8)
    int screenTop();

    @VTID(9)
    boolean attachEvent(
        java.lang.String event,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pdisp);

    @VTID(10)
    void detachEvent(
        java.lang.String event,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pdisp);

    @VTID(11)
    int setTimeout(
        java.lang.Object expression,
        int msec,
        java.lang.Object language);

    @VTID(12)
    int setInterval(
        java.lang.Object expression,
        int msec,
        java.lang.Object language);

    @VTID(13)
    void print();

    @VTID(14)
    void onbeforeprint(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforeprint();

    @VTID(16)
    void onafterprint(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onafterprint();

    @VTID(18)
    mol.mshtml.IHTMLDataTransfer clipboardData();

    @VTID(19)
    mol.mshtml.IHTMLWindow2 showModelessDialog(
        java.lang.String url,
        java.lang.Object varArgIn,
        java.lang.Object options);

}
