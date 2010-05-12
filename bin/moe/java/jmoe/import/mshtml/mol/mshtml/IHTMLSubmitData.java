package mol.mshtml  ;

import com4j.*;

@IID("{3050F645-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLSubmitData extends Com4jObject {
    @VTID(7)
    void appendNameValuePair(
        java.lang.String name,
        java.lang.String value);

    @VTID(8)
    void appendNameFilePair(
        java.lang.String name,
        java.lang.String filename);

    @VTID(9)
    void appendItemSeparator();

}
