package mol.mshtml  ;

import com4j.*;

@IID("{3050F3D1-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLStyleSheet2 extends Com4jObject {
    @VTID(7)
    mol.mshtml.IHTMLStyleSheetPagesCollection pages();

    @VTID(7)
    @ReturnValue(defaultPropertyThrough={mol.mshtml.IHTMLStyleSheetPagesCollection.class})
    mol.mshtml.IHTMLStyleSheetPage pages(
        int index);

    @VTID(8)
    int addPageRule(
        java.lang.String bstrSelector,
        java.lang.String bstrStyle,
        int lIndex);

}
