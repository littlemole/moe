package mol.office  ;

import com4j.*;

@IID("{000CDB0F-0000-0000-C000-000000000046}")
public interface CustomXMLValidationErrors extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    mol.office.CustomXMLValidationError item(
        int index);

    @VTID(12)
    void add(
        mol.office.CustomXMLNode node,
        java.lang.String errorName,
        java.lang.String errorText,
        boolean clearedOnUpdate);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

}
