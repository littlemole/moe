package mol.mshtml  ;

import com4j.*;

@IID("{3050F6B5-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLIPrintCollection extends Com4jObject {
    @VTID(7)
    int length();

    @VTID(8)
    com4j.Com4jObject _newEnum();

    @VTID(9)
    @DefaultMethod
    com4j.Com4jObject item(
        int index);

}
