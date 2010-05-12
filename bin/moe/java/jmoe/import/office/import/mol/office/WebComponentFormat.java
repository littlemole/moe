package mol.office  ;

import com4j.*;

@IID("{000CD102-0000-0000-C000-000000000046}")
public interface WebComponentFormat extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject application();

    @VTID(8)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(9)
    java.lang.String url();

    @VTID(10)
    void url(
        java.lang.String retValue);

    @VTID(11)
    java.lang.String html();

    @VTID(12)
    void html(
        java.lang.String retValue);

    @VTID(13)
    java.lang.String name();

    @VTID(14)
    void name(
        java.lang.String retValue);

    @VTID(15)
    int width();

    @VTID(16)
    void width(
        int retValue);

    @VTID(17)
    int height();

    @VTID(18)
    void height(
        int retValue);

    @VTID(19)
    java.lang.String previewGraphic();

    @VTID(20)
    void previewGraphic(
        java.lang.String retval);

    @VTID(21)
    void launchPropertiesWindow();

}
