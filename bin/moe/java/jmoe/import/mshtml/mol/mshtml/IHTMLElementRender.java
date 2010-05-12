package mol.mshtml  ;

import com4j.*;

@IID("{3050F669-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLElementRender extends Com4jObject {
    @VTID(3)
    void drawToDC(
        int hdc);

    @VTID(4)
    void setDocumentPrinter(
        java.lang.String bstrPrinterName,
        int hdc);

}
