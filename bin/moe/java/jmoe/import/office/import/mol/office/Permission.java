package mol.office  ;

import com4j.*;

@IID("{000C0376-0000-0000-C000-000000000046}")
public interface Permission extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.UserPermission item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(10)
    int count();

    @VTID(11)
    boolean enableTrustedBrowser();

    @VTID(12)
    void enableTrustedBrowser(
        boolean enable);

    @VTID(13)
    mol.office.UserPermission add(
        java.lang.String userId,
        @MarshalAs(NativeType.VARIANT) java.lang.Object permission,
        @MarshalAs(NativeType.VARIANT) java.lang.Object expirationDate);

    @VTID(14)
    void applyPolicy(
        java.lang.String fileName);

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(16)
    void removeAll();

    @VTID(17)
    boolean enabled();

    @VTID(18)
    void enabled(
        boolean enabled);

    @VTID(19)
    java.lang.String requestPermissionURL();

    @VTID(20)
    void requestPermissionURL(
        java.lang.String contact);

    @VTID(21)
    java.lang.String policyName();

    @VTID(22)
    java.lang.String policyDescription();

    @VTID(23)
    boolean storeLicenses();

    @VTID(24)
    void storeLicenses(
        boolean enabled);

    @VTID(25)
    java.lang.String documentAuthor();

    @VTID(26)
    void documentAuthor(
        java.lang.String author);

    @VTID(27)
    boolean permissionFromPolicy();

    @VTID(28)
    java.util.Iterator<Com4jObject> iterator();

}
