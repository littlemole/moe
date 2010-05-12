package mol.office  ;

import com4j.*;

@IID("{000C03C5-0000-0000-C000-000000000046}")
public interface IBlogPictureExtensibility extends Com4jObject {
    @VTID(7)
    void blogPictureProviderProperties(
        Holder<java.lang.String> blogPictureProvider,
        Holder<java.lang.String> friendlyName);

    @VTID(8)
    void createPictureAccount(
        java.lang.String account,
        java.lang.String blogProvider,
        int parentWindow,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject document);

    @VTID(9)
    @ReturnValue(index=4)
    java.lang.String publishPicture(
        java.lang.String account,
        int parentWindow,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject document,
        com4j.Com4jObject image,
        int imageType);

}
