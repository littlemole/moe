package mol.office  ;

import com4j.*;

@IID("{000CD6A1-0000-0000-C000-000000000046}")
public interface SignatureSetup extends mol.office._IMsoDispObj {
    @VTID(9)
    boolean readOnly();

    @VTID(10)
    java.lang.String id();

    @VTID(11)
    java.lang.String signatureProvider();

    @VTID(12)
    java.lang.String suggestedSigner();

    @VTID(13)
    void suggestedSigner(
        java.lang.String pbstr);

    @VTID(14)
    java.lang.String suggestedSignerLine2();

    @VTID(15)
    void suggestedSignerLine2(
        java.lang.String pbstr);

    @VTID(16)
    java.lang.String suggestedSignerEmail();

    @VTID(17)
    void suggestedSignerEmail(
        java.lang.String pbstr);

    @VTID(18)
    java.lang.String signingInstructions();

    @VTID(19)
    void signingInstructions(
        java.lang.String pbstr);

    @VTID(20)
    boolean allowComments();

    @VTID(21)
    void allowComments(
        boolean pvarf);

    @VTID(22)
    boolean showSignDate();

    @VTID(23)
    void showSignDate(
        boolean pvarf);

    @VTID(24)
    java.lang.String additionalXml();

    @VTID(25)
    void additionalXml(
        java.lang.String pbstr);

}
