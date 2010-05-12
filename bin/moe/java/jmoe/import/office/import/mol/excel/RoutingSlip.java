package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface RoutingSlip extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(955)
    @PropGet
    mol.excel.XlRoutingSlipDelivery delivery();

    @DISPID(955)
    @PropPut
    void delivery(
        mol.excel.XlRoutingSlipDelivery rhs);

    @DISPID(954)
    @PropGet
    java.lang.Object message();

    @DISPID(954)
    @PropPut
    void message(
        java.lang.Object rhs);

    @DISPID(952)
    @PropGet
    java.lang.Object recipients(
        java.lang.Object index);

    @DISPID(952)
    @PropPut
    void recipients(
        java.lang.Object index,
        java.lang.Object rhs);

    @DISPID(555)
    java.lang.Object reset();

    @DISPID(956)
    @PropGet
    boolean returnWhenDone();

    @DISPID(956)
    @PropPut
    void returnWhenDone(
        boolean rhs);

    @DISPID(958)
    @PropGet
    mol.excel.XlRoutingSlipStatus status();

    @DISPID(953)
    @PropGet
    java.lang.Object subject();

    @DISPID(953)
    @PropPut
    void subject(
        java.lang.Object rhs);

    @DISPID(957)
    @PropGet
    boolean trackStatus();

    @DISPID(957)
    @PropPut
    void trackStatus(
        boolean rhs);

}
