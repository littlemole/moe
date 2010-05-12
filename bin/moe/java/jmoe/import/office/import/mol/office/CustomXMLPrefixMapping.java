package mol.office  ;

import com4j.*;

@IID("{000CDB10-0000-0000-C000-000000000046}")
public interface CustomXMLPrefixMapping extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String prefix();

    @VTID(11)
    java.lang.String namespaceURI();

}
