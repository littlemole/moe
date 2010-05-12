package mol.office  ;

import com4j.*;

@IID("{000C03C4-0000-0000-C000-000000000046}")
public interface IBlogExtensibility extends Com4jObject {
    @VTID(7)
    void blogProviderProperties(
        Holder<java.lang.String> blogProvider,
        Holder<java.lang.String> friendlyName,
        Holder<mol.office.MsoBlogCategorySupport> categorySupport,
        Holder<Boolean> padding);

    @VTID(8)
    boolean setupBlogAccount(
        java.lang.String account,
        int parentWindow,
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject document,
        boolean newAccount);

                @VTID(12)
                void publishPost(
                    java.lang.String account,
                    int parentWindow,
                    @MarshalAs(NativeType.Dispatch) com4j.Com4jObject document,
                    java.lang.String xHTML,
                    java.lang.String title,
                    java.lang.String dateTime,
                    java.lang.String[] categories,
                    boolean draft,
                    Holder<java.lang.String> postID,
                    Holder<java.lang.String> publishMessage);

                @VTID(13)
                java.lang.String republishPost(
                    java.lang.String account,
                    int parentWindow,
                    @MarshalAs(NativeType.Dispatch) com4j.Com4jObject document,
                    java.lang.String postID,
                    java.lang.String xHTML,
                    java.lang.String title,
                    java.lang.String dateTime,
                    java.lang.String[] categories,
                    boolean draft);

                @VTID(14)
                java.lang.String[] getCategories(
                    java.lang.String account,
                    int parentWindow,
                    @MarshalAs(NativeType.Dispatch) com4j.Com4jObject document);

            }
