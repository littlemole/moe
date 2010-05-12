package mol.office  ;

import com4j.*;

@IID("{000C0411-0000-0000-C000-000000000046}")
public interface Signature extends mol.office._IMsoDispObj {
    @VTID(9)
    java.lang.String signer();

    @VTID(10)
    java.lang.String issuer();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object expireDate();

    @VTID(12)
    boolean isValid();

    @VTID(13)
    boolean attachCertificate();

    @VTID(14)
    void attachCertificate(
        boolean pvarfAttach);

    @VTID(15)
    void delete();

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(17)
    boolean isCertificateExpired();

    @VTID(18)
    boolean isCertificateRevoked();

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object signDate();

    @VTID(20)
    boolean isSigned();

    @VTID(21)
    void sign(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varSigImg,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varDelSuggSigner,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varDelSuggSignerLine2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object varDelSuggSignerEmail);

    @VTID(22)
    mol.office.SignatureInfo details();

    @VTID(23)
    void showDetails();

    @VTID(24)
    boolean canSetup();

    @VTID(25)
    mol.office.SignatureSetup setup();

    @VTID(26)
    boolean isSignatureLine();

    @VTID(27)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject signatureLineShape();

    @VTID(28)
    int sortHint();

}
