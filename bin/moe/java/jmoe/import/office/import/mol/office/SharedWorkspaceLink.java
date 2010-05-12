package mol.office  ;

import com4j.*;

@IID("{000C037F-0000-0000-C000-000000000046}")
public interface SharedWorkspaceLink extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String url();

    @VTID(10)
    @DefaultMethod
    void url(
        java.lang.String url);

    @VTID(11)
    java.lang.String description();

    @VTID(12)
    void description(
        java.lang.String description);

    @VTID(13)
    java.lang.String notes();

    @VTID(14)
    void notes(
        java.lang.String notes);

    @VTID(15)
    java.lang.String createdBy();

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object createdDate();

    @VTID(17)
    java.lang.String modifiedBy();

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object modifiedDate();

    @VTID(19)
    void save();

    @VTID(20)
    void delete();

    @VTID(21)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
