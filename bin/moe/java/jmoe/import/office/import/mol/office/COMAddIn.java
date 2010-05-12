package mol.office  ;

import com4j.*;

@IID("{000C033A-0000-0000-C000-000000000046}")
public interface COMAddIn extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String description();

    @VTID(10)
    @DefaultMethod
    void description(
        java.lang.String retValue);

    @VTID(11)
    java.lang.String progId();

    @VTID(12)
    java.lang.String guid();

    @VTID(13)
    boolean connect();

    @VTID(14)
    void connect(
        boolean retValue);

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject object();

    @VTID(16)
    void object(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject retValue);

    @VTID(17)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
