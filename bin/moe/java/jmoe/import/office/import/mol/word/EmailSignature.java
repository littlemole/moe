package mol.word  ;

import com4j.*;

@IID("{000209DC-0000-0000-C000-000000000046}")
public interface EmailSignature extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String newMessageSignature();

    @VTID(11)
    void newMessageSignature(
        java.lang.String prop);

    @VTID(12)
    java.lang.String replyMessageSignature();

    @VTID(13)
    void replyMessageSignature(
        java.lang.String prop);

    @VTID(14)
    mol.word.EmailSignatureEntries emailSignatureEntries();

    @VTID(14)
    @ReturnValue(defaultPropertyThrough={mol.word.EmailSignatureEntries.class})
    mol.word.EmailSignatureEntry emailSignatureEntries(
        java.lang.Object index);

}
