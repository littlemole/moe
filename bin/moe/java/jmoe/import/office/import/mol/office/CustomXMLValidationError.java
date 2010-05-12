package mol.office  ;

import com4j.*;

@IID("{000CDB0E-0000-0000-C000-000000000046}")
public interface CustomXMLValidationError extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    mol.office.CustomXMLNode node();

    @VTID(12)
    java.lang.String text();

    @VTID(13)
    mol.office.MsoCustomXMLValidationErrorType type();

    @VTID(14)
    void delete();

    @VTID(15)
    int errorCode();

}
