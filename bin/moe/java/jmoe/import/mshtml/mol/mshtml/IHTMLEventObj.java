package mol.mshtml  ;

import com4j.*;

@IID("{3050F32D-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLEventObj extends Com4jObject {
    @VTID(7)
    mol.mshtml.IHTMLElement srcElement();

    @VTID(8)
    boolean altKey();

    @VTID(9)
    boolean ctrlKey();

    @VTID(10)
    boolean shiftKey();

    @VTID(11)
    void returnValue(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object returnValue();

    @VTID(13)
    void cancelBubble(
        boolean p);

    @VTID(14)
    boolean cancelBubble();

    @VTID(15)
    mol.mshtml.IHTMLElement fromElement();

    @VTID(16)
    mol.mshtml.IHTMLElement toElement();

    @VTID(17)
    void keyCode(
        int p);

    @VTID(18)
    int keyCode();

    @VTID(19)
    int button();

    @VTID(20)
    java.lang.String type();

    @VTID(21)
    java.lang.String qualifier();

    @VTID(22)
    int reason();

    @VTID(23)
    int x();

    @VTID(24)
    int y();

    @VTID(25)
    int clientX();

    @VTID(26)
    int clientY();

    @VTID(27)
    int offsetX();

    @VTID(28)
    int offsetY();

    @VTID(29)
    int screenX();

    @VTID(30)
    int screenY();

    @VTID(31)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject srcFilter();

}
