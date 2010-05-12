package mol.mshtml  ;

import com4j.*;

@IID("{3050F69D-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IDisplayServices extends Com4jObject {
    @VTID(3)
    mol.mshtml.IDisplayPointer createDisplayPointer();

            @VTID(6)
            mol.mshtml.IHTMLCaret getCaret();

            @VTID(7)
            mol.mshtml.IHTMLComputedStyle getComputedStyle(
                mol.mshtml.IMarkupPointer pPointer);

                @VTID(9)
                int hasFlowLayout(
                    mol.mshtml.IHTMLElement pIElement);

            }
