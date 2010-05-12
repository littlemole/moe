package mol.mshtml  ;

import com4j.*;

@IID("{3050F2E5-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLStyleSheetRulesCollection extends Com4jObject {
    @VTID(7)
    int length();

    @VTID(8)
    @DefaultMethod
    mol.mshtml.IHTMLStyleSheetRule item(
        int index);

}
