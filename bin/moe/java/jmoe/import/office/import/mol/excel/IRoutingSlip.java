package mol.excel  ;

import com4j.*;

@IID("{000208AA-0001-0000-C000-000000000046}")
public interface IRoutingSlip extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.XlRoutingSlipDelivery delivery();

    @VTID(11)
    void delivery(
        mol.excel.XlRoutingSlipDelivery rhs);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object message();

    @VTID(13)
    void message(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object recipients(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(15)
    void recipients(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object reset();

    @VTID(17)
    boolean returnWhenDone();

    @VTID(18)
    void returnWhenDone(
        boolean rhs);

    @VTID(19)
    mol.excel.XlRoutingSlipStatus status();

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object subject();

    @VTID(21)
    void subject(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(22)
    boolean trackStatus();

    @VTID(23)
    void trackStatus(
        boolean rhs);

}
