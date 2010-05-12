package mol.office  ;

import com4j.*;

@IID("{000CD809-0000-0000-C000-000000000046}")
public interface EncryptionProvider extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object getProviderDetail(
        mol.office.EncryptionProviderDetail encprovdet);

    @VTID(8)
    int newSession(
        com4j.Com4jObject parentWindow);

    @VTID(9)
    int authenticate(
        com4j.Com4jObject parentWindow,
        com4j.Com4jObject encryptionData,
        Holder<Integer> permissionsMask);

    @VTID(10)
    int cloneSession(
        int sessionHandle);

    @VTID(11)
    void endSession(
        int sessionHandle);

    @VTID(12)
    int save(
        int sessionHandle,
        com4j.Com4jObject encryptionData);

    @VTID(13)
    void encryptStream(
        int sessionHandle,
        java.lang.String streamName,
        com4j.Com4jObject unencryptedStream,
        com4j.Com4jObject encryptedStream);

    @VTID(14)
    void decryptStream(
        int sessionHandle,
        java.lang.String streamName,
        com4j.Com4jObject encryptedStream,
        com4j.Com4jObject unencryptedStream);

    @VTID(15)
    boolean showSettings(
        int sessionHandle,
        com4j.Com4jObject parentWindow,
        boolean readOnly);

}
