package mol.office  ;

import com4j.*;

@IID("{000C0306-0000-0000-C000-000000000046}")
public interface CommandBarControls extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    mol.office.CommandBarControl add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object id,
        @MarshalAs(NativeType.VARIANT) java.lang.Object parameter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object temporary);

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    mol.office.CommandBarControl item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(13)
    mol.office.CommandBar parent();

}
