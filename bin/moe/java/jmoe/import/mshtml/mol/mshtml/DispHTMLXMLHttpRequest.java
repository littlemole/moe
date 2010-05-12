package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTMLXMLHttpRequest extends Com4jObject {
    @DISPID(1002)
    @PropGet
    int readyState();

    @DISPID(1003)
    @PropGet
    java.lang.Object responseBody();

    @DISPID(1004)
    @PropGet
    java.lang.String responseText();

    @DISPID(1005)
    @PropGet
    com4j.Com4jObject responseXML();

    @DISPID(1006)
    @PropGet
    int status();

    @DISPID(1007)
    @PropGet
    java.lang.String statusText();

    @DISPID(1008)
    @PropPut
    void onreadystatechange(
        java.lang.Object rhs);

    @DISPID(1008)
    @PropGet
    java.lang.Object onreadystatechange();

    @DISPID(1009)
    void abort();

    @DISPID(1010)
    void open(
        java.lang.String bstrMethod,
        java.lang.String bstrUrl,
        java.lang.Object varAsync,
        java.lang.Object varUser,
        java.lang.Object varPassword);

    @DISPID(1011)
    void send(
        java.lang.Object varBody);

    @DISPID(1012)
    java.lang.String getAllResponseHeaders();

    @DISPID(1013)
    java.lang.String getResponseHeader(
        java.lang.String bstrHeader);

    @DISPID(1014)
    void setRequestHeader(
        java.lang.String bstrHeader,
        java.lang.String bstrValue);

}
