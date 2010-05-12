package mol.mshtml  ;

import com4j.*;

@IID("{3050F1F4-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLHRElement extends Com4jObject {
    @VTID(7)
    void align(
        java.lang.String p);

    @VTID(8)
    java.lang.String align();

    @VTID(9)
    void color(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object color();

    @VTID(11)
    void noShade(
        boolean p);

    @VTID(12)
    boolean noShade();

    @VTID(13)
    void width(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object width();

    @VTID(15)
    void size(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object size();

}
