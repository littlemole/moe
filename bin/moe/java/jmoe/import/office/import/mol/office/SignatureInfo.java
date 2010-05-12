package mol.office  ;

import com4j.*;

@IID("{000CD6A2-0000-0000-C000-000000000046}")
public interface SignatureInfo extends mol.office._IMsoDispObj {
    @VTID(9)
    boolean readOnly();

    @VTID(10)
    java.lang.String signatureProvider();

    @VTID(11)
    java.lang.String signatureText();

    @VTID(12)
    void signatureText(
        java.lang.String pbstr);

        @VTID(15)
        java.lang.String signatureComment();

        @VTID(16)
        void signatureComment(
            java.lang.String pbstr);

        @VTID(17)
        @ReturnValue(type=NativeType.VARIANT)
        java.lang.Object getSignatureDetail(
            mol.office.SignatureDetail sigdet);

        @VTID(18)
        @ReturnValue(type=NativeType.VARIANT)
        java.lang.Object getCertificateDetail(
            mol.office.CertificateDetail certdet);

        @VTID(19)
        mol.office.ContentVerificationResults contentVerificationResults();

        @VTID(20)
        mol.office.CertificateVerificationResults certificateVerificationResults();

        @VTID(21)
        boolean isValid();

        @VTID(22)
        boolean isCertificateExpired();

        @VTID(23)
        boolean isCertificateRevoked();

        @VTID(24)
        boolean isCertificateUntrusted();

        @VTID(25)
        void showSignatureCertificate(
            com4j.Com4jObject parentWindow);

        @VTID(26)
        void selectSignatureCertificate(
            com4j.Com4jObject parentWindow);

        @VTID(27)
        void selectCertificateDetailByThumbprint(
            java.lang.String bstrThumbprint);

    }
