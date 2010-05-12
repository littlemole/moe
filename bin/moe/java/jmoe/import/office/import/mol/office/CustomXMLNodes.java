package mol.office  ;

import com4j.*;

@IID("{000CDB03-0000-0000-C000-000000000046}")
public interface CustomXMLNodes extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    mol.office.CustomXMLNode item(
        int index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

}
