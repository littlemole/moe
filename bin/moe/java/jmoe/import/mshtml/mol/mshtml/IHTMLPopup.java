package mol.mshtml  ;

import com4j.*;

@IID("{3050F666-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLPopup extends Com4jObject {
    @VTID(7)
    void show(
        int x,
        int y,
        int w,
        int h,
        java.lang.Object pElement);

    @VTID(8)
    void hide();

    @VTID(9)
    mol.mshtml.IHTMLDocument document();

    @VTID(10)
    boolean isOpen();

}
