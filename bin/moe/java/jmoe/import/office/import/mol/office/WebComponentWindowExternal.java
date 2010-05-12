package mol.office  ;

import com4j.*;

@IID("{000CD101-0000-0000-C000-000000000046}")
public interface WebComponentWindowExternal extends Com4jObject {
    @VTID(7)
    int interfaceVersion();

    @VTID(8)
    java.lang.String applicationName();

    @VTID(9)
    int applicationVersion();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject application();

    @VTID(11)
    void closeWindow();

    @VTID(12)
    mol.office.WebComponent webComponent();

}
