package mol.word  ;

import com4j.*;

@IID("{00020969-0000-0000-C000-000000000046}")
public interface RoutingSlip extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String subject();

    @VTID(11)
    void subject(
        java.lang.String prop);

    @VTID(12)
    java.lang.String message();

    @VTID(13)
    void message(
        java.lang.String prop);

    @VTID(14)
    mol.word.WdRoutingSlipDelivery delivery();

    @VTID(15)
    void delivery(
        mol.word.WdRoutingSlipDelivery prop);

    @VTID(16)
    boolean trackStatus();

    @VTID(17)
    void trackStatus(
        boolean prop);

    @VTID(18)
    mol.word.WdProtectionType protect();

    @VTID(19)
    void protect(
        mol.word.WdProtectionType prop);

    @VTID(20)
    boolean returnWhenDone();

    @VTID(21)
    void returnWhenDone(
        boolean prop);

    @VTID(22)
    mol.word.WdRoutingSlipStatus status();

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object recipients(
        java.lang.Object index);

    @VTID(24)
    void reset();

    @VTID(25)
    void addRecipient(
        java.lang.String recipient);

}
