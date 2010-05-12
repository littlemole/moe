package mol.office  ;

import com4j.*;

@IID("{000C1532-0000-0000-C000-000000000046}")
public interface ODSOColumns extends mol.office._IMsoDispObj {
    @VTID(9)
    int count();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varIndex);

}
