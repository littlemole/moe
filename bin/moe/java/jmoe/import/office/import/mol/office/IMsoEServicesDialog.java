package mol.office  ;

import com4j.*;

@IID("{000C0372-0000-0000-C000-000000000046}")
public interface IMsoEServicesDialog extends Com4jObject {
    @VTID(7)
    void close(
        boolean applyWebComponentChanges);

    @VTID(8)
    void addTrustedDomain(
        java.lang.String domain);

    @VTID(9)
    java.lang.String applicationName();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject application();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject webComponent();

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject clipArt();

}
