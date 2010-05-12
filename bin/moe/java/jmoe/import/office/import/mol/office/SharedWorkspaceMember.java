package mol.office  ;

import com4j.*;

@IID("{000C0381-0000-0000-C000-000000000046}")
public interface SharedWorkspaceMember extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String domainName();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    java.lang.String email();

    @VTID(12)
    void delete();

    @VTID(13)
    java.lang.String id();

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
