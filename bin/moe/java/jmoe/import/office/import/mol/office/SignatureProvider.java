package mol.office  ;

import com4j.*;

@IID("{000CD6A3-0000-0000-C000-000000000046}")
public interface SignatureProvider extends Com4jObject {
    @VTID(8)
    void showSignatureSetup(
        com4j.Com4jObject parentWindow,
        mol.office.SignatureSetup psigsetup);

    @VTID(9)
    void showSigningCeremony(
        com4j.Com4jObject parentWindow,
        mol.office.SignatureSetup psigsetup,
        mol.office.SignatureInfo psiginfo);

    @VTID(10)
    void signXmlDsig(
        com4j.Com4jObject queryContinue,
        mol.office.SignatureSetup psigsetup,
        mol.office.SignatureInfo psiginfo,
        com4j.Com4jObject xmlDsigStream);

    @VTID(11)
    void notifySignatureAdded(
        com4j.Com4jObject parentWindow,
        mol.office.SignatureSetup psigsetup,
        mol.office.SignatureInfo psiginfo);

    @VTID(12)
    void verifyXmlDsig(
        com4j.Com4jObject queryContinue,
        mol.office.SignatureSetup psigsetup,
        mol.office.SignatureInfo psiginfo,
        com4j.Com4jObject xmlDsigStream,
        Holder<mol.office.ContentVerificationResults> pcontverres,
        Holder<mol.office.CertificateVerificationResults> pcertverres);

    @VTID(13)
    void showSignatureDetails(
        com4j.Com4jObject parentWindow,
        mol.office.SignatureSetup psigsetup,
        mol.office.SignatureInfo psiginfo,
        com4j.Com4jObject xmlDsigStream,
        Holder<mol.office.ContentVerificationResults> pcontverres,
        Holder<mol.office.CertificateVerificationResults> pcertverres);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object getProviderDetail(
        mol.office.SignatureProviderDetail sigprovdet);

    @VTID(15)
    byte[] hashStream(
        com4j.Com4jObject queryContinue,
        com4j.Com4jObject stream);

}
