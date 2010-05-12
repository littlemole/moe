package mol.mshtml  ;

import com4j.*;

@IID("{3050F6DB-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLFrameBase2 extends Com4jObject {
    @VTID(7)
    mol.mshtml.IHTMLWindow2 contentWindow();

    @VTID(8)
    void onload(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(9)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onload();

    @VTID(10)
    void onreadystatechange(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onreadystatechange();

    @VTID(12)
    java.lang.String readyState();

    @VTID(13)
    void allowTransparency(
        boolean p);

    @VTID(14)
    boolean allowTransparency();

}
