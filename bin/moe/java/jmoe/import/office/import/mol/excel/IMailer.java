package mol.excel  ;

import com4j.*;

@IID("{000208D1-0001-0000-C000-000000000046}")
public interface IMailer extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bccRecipients();

    @VTID(11)
    void bccRecipients(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ccRecipients();

    @VTID(13)
    void ccRecipients(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object enclosures();

    @VTID(15)
    void enclosures(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(16)
    boolean received();

    @VTID(17)
    java.util.Date sendDateTime();

    @VTID(18)
    java.lang.String sender();

    @VTID(19)
    java.lang.String subject();

    @VTID(20)
    void subject(
        java.lang.String rhs);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object toRecipients();

    @VTID(22)
    void toRecipients(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object whichAddress();

    @VTID(24)
    void whichAddress(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

}
