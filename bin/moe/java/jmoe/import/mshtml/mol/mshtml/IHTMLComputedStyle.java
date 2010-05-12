package mol.mshtml  ;

import com4j.*;

@IID("{3050F6C3-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLComputedStyle extends Com4jObject {
    @VTID(3)
    boolean bold();

    @VTID(4)
    boolean italic();

    @VTID(5)
    boolean underline();

    @VTID(6)
    boolean overline();

    @VTID(7)
    boolean strikeOut();

    @VTID(8)
    boolean subScript();

    @VTID(9)
    boolean superScript();

    @VTID(10)
    boolean explicitFace();

    @VTID(11)
    int fontWeight();

    @VTID(12)
    int fontSize();

    @VTID(13)
    short fontName();

    @VTID(14)
    boolean hasBgColor();

    @VTID(15)
    int textColor();

    @VTID(16)
    int backgroundColor();

    @VTID(17)
    boolean preFormatted();

    @VTID(18)
    boolean direction();

    @VTID(19)
    boolean blockDirection();

    @VTID(20)
    boolean ol();

    @VTID(21)
    boolean isEqual(
        mol.mshtml.IHTMLComputedStyle pComputedStyle);

}
