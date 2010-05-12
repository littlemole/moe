package mol.mshtml  ;

import com4j.*;

@IID("{3051040A-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLXMLHttpRequest extends Com4jObject {
    @VTID(7)
    int readyState();

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object responseBody();

    @VTID(9)
    java.lang.String responseText();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject responseXML();

    @VTID(11)
    int status();

    @VTID(12)
    java.lang.String statusText();

    @VTID(13)
    void onreadystatechange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onreadystatechange();

    @VTID(15)
    void abort();

    @VTID(16)
    void open(
        java.lang.String bstrMethod,
        java.lang.String bstrUrl,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varAsync,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varUser,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varPassword);

    @VTID(17)
    void send(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varBody);

    @VTID(18)
    java.lang.String getAllResponseHeaders();

    @VTID(19)
    java.lang.String getResponseHeader(
        java.lang.String bstrHeader);

    @VTID(20)
    void setRequestHeader(
        java.lang.String bstrHeader,
        java.lang.String bstrValue);

}
