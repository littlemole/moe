package mol.office  ;

import com4j.*;

@IID("{000C030D-0000-0000-C000-000000000046}")
public interface _CommandBarActiveX extends mol.office.CommandBarControl {
    @VTID(83)
    java.lang.String controlCLSID();

    @VTID(84)
    void controlCLSID(
        java.lang.String pbstrClsid);

    @VTID(85)
    com4j.Com4jObject queryControlInterface(
        java.lang.String bstrIid);

    @VTID(86)
    void setInnerObjectFactory(
        com4j.Com4jObject pUnk);

    @VTID(87)
    void ensureControl();

    @VTID(88)
    void initWith(
        com4j.Com4jObject rhs);

}
