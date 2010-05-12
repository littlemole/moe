package mol.mshtml  ;

import com4j.*;

@IID("{3050F6BB-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLNamespace extends Com4jObject {
    @VTID(7)
    java.lang.String name();

    @VTID(8)
    java.lang.String urn();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject tagNames();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object readyState();

    @VTID(11)
    void onreadystatechange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onreadystatechange();

    @VTID(13)
    void doImport(
        java.lang.String bstrImplementationUrl);

    @VTID(14)
    boolean attachEvent(
        java.lang.String event,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pdisp);

    @VTID(15)
    void detachEvent(
        java.lang.String event,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pdisp);

}
