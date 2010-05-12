package mol.mshtml  ;

import com4j.*;

@IID("{3050F809-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLDOMTextNode2 extends Com4jObject {
    @VTID(7)
    java.lang.String substringData(
        int offset,
        int count);

    @VTID(8)
    void appendData(
        java.lang.String bstrstring);

    @VTID(9)
    void insertData(
        int offset,
        java.lang.String bstrstring);

    @VTID(10)
    void deleteData(
        int offset,
        int count);

    @VTID(11)
    void replaceData(
        int offset,
        int count,
        java.lang.String bstrstring);

}
