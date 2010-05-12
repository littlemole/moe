package mol.mshtml  ;

import com4j.*;

@IID("{3050F23A-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLTableCol extends Com4jObject {
    @VTID(7)
    void span(
        int p);

    @VTID(8)
    int span();

    @VTID(9)
    void width(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object width();

    @VTID(11)
    void align(
        java.lang.String p);

    @VTID(12)
    java.lang.String align();

    @VTID(13)
    void vAlign(
        java.lang.String p);

    @VTID(14)
    java.lang.String vAlign();

}
