package mol.office  ;

import com4j.*;

@IID("{000C038F-0000-0000-C000-000000000046}")
public interface MetaProperty extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value();

    @VTID(10)
    @DefaultMethod
    void value(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pvarValue);

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    java.lang.String id();

    @VTID(13)
    boolean isReadOnly();

    @VTID(14)
    boolean isRequired();

    @VTID(15)
    mol.office.MsoMetaPropertyType type();

    @VTID(16)
    java.lang.String validate();

    @VTID(17)
    java.lang.String validationError();

    @VTID(18)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
