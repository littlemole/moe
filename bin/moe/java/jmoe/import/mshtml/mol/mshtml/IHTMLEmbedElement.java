package mol.mshtml  ;

import com4j.*;

@IID("{3050F25F-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLEmbedElement extends Com4jObject {
    @VTID(7)
    void hidden(
        java.lang.String p);

    @VTID(8)
    java.lang.String hidden();

    @VTID(9)
    java.lang.String palette();

    @VTID(10)
    java.lang.String pluginspage();

    @VTID(11)
    void src(
        java.lang.String p);

    @VTID(12)
    java.lang.String src();

    @VTID(13)
    void units(
        java.lang.String p);

    @VTID(14)
    java.lang.String units();

    @VTID(15)
    void name(
        java.lang.String p);

    @VTID(16)
    java.lang.String name();

    @VTID(17)
    void width(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object width();

    @VTID(19)
    void height(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object height();

}
