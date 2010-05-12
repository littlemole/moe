package mol.office  ;

import com4j.*;

@IID("{000C038E-0000-0000-C000-000000000046}")
public interface MetaProperties extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.MetaProperty item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(10)
    mol.office.MetaProperty getItemByInternalName(
        java.lang.String internalName);

    @VTID(11)
    int count();

    @VTID(12)
    java.lang.String validate();

    @VTID(13)
    java.lang.String validationError();

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(15)
    java.lang.String schemaXml();

    @VTID(16)
    java.util.Iterator<Com4jObject> iterator();

}
