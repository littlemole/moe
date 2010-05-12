package mol.mshtml  ;

import com4j.*;

@IID("{3050F4B1-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLDOMTextNode extends Com4jObject {
    @VTID(7)
    void data(
        java.lang.String p);

    @VTID(8)
    java.lang.String data();

    @VTID(9)
    java.lang.String toString_();

    @VTID(10)
    int length();

    @VTID(11)
    mol.mshtml.IHTMLDOMNode splitText(
        int offset);

}
