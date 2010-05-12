package mol.office  ;

import com4j.*;

@IID("{000CD100-0000-0000-C000-000000000046}")
public interface WebComponent extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject shape();

    @VTID(8)
    java.lang.String url();

    @VTID(9)
    void url(
        java.lang.String retValue);

    @VTID(10)
    java.lang.String html();

    @VTID(11)
    void html(
        java.lang.String retValue);

    @VTID(12)
    java.lang.String name();

    @VTID(13)
    void name(
        java.lang.String retValue);

    @VTID(14)
    int width();

    @VTID(15)
    void width(
        int retValue);

    @VTID(16)
    int height();

    @VTID(17)
    void height(
        int retValue);

    @VTID(18)
    void setPlaceHolderGraphic(
        java.lang.String placeHolderGraphic);

    @VTID(19)
    void commit();

    @VTID(20)
    void revert();

}
