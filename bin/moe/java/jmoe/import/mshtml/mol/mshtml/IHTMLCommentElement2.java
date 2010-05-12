package mol.mshtml  ;

import com4j.*;

@IID("{3050F813-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLCommentElement2 extends Com4jObject {
    @VTID(7)
    void data(
        java.lang.String p);

    @VTID(8)
    java.lang.String data();

    @VTID(9)
    int length();

    @VTID(10)
    java.lang.String substringData(
        int offset,
        int count);

    @VTID(11)
    void appendData(
        java.lang.String bstrstring);

    @VTID(12)
    void insertData(
        int offset,
        java.lang.String bstrstring);

    @VTID(13)
    void deleteData(
        int offset,
        int count);

    @VTID(14)
    void replaceData(
        int offset,
        int count,
        java.lang.String bstrstring);

}
