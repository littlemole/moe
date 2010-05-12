package mol.mshtml  ;

import com4j.*;

@IID("{3050F1D9-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLFontElement extends Com4jObject {
    @VTID(7)
    void color(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object color();

    @VTID(9)
    void face(
        java.lang.String p);

    @VTID(10)
    java.lang.String face();

    @VTID(11)
    void size(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object size();

}
