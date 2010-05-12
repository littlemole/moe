package mol.office  ;

import com4j.*;

@IID("{000C0936-0000-0000-C000-000000000046}")
public interface NewFile extends mol.office._IMsoDispObj {
    @VTID(9)
    boolean add(
        java.lang.String fileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object section,
        @MarshalAs(NativeType.VARIANT) java.lang.Object displayName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object action);

    @VTID(10)
    boolean remove(
        java.lang.String fileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object section,
        @MarshalAs(NativeType.VARIANT) java.lang.Object displayName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object action);

}
