package mol.mshtml  ;

import com4j.*;

@IID("{3050F4A6-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLTextRangeMetrics2 extends Com4jObject {
    @VTID(7)
    mol.mshtml.IHTMLRectCollection getClientRects();

    @VTID(7)
    @ReturnValue(type=NativeType.VARIANT,defaultPropertyThrough={mol.mshtml.IHTMLRectCollection.class})
    java.lang.Object getClientRects(
        java.lang.Object pvarIndex);

    @VTID(8)
    mol.mshtml.IHTMLRect getBoundingClientRect();

}
