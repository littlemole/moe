package mol.word  ;

import com4j.*;

@IID("{000209BD-0000-0000-C000-000000000046}")
public interface Mailer extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bccRecipients();

    @VTID(11)
    void bccRecipients(
        java.lang.Object prop);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ccRecipients();

    @VTID(13)
    void ccRecipients(
        java.lang.Object prop);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object recipients();

    @VTID(15)
    void recipients(
        java.lang.Object prop);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object enclosures();

    @VTID(17)
    void enclosures(
        java.lang.Object prop);

    @VTID(18)
    java.lang.String sender();

    @VTID(19)
    java.util.Date sendDateTime();

    @VTID(20)
    boolean received();

    @VTID(21)
    java.lang.String subject();

    @VTID(22)
    void subject(
        java.lang.String prop);

}
