package mol.office  ;

import com4j.*;

@IID("{000C0410-0000-0000-C000-000000000046}")
public interface SignatureSet extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    mol.office.Signature item(
        int iSig);

    @VTID(12)
    mol.office.Signature add();

    @VTID(13)
    void commit();

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(15)
    mol.office.Signature addNonVisibleSignature(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varSigProv);

    @VTID(16)
    boolean canAddSignatureLine();

    @VTID(17)
    mol.office.Signature addSignatureLine(
        @MarshalAs(NativeType.VARIANT) java.lang.Object varSigProv);

    @VTID(18)
    mol.office.MsoSignatureSubset subset();

    @VTID(19)
    void subset(
        mol.office.MsoSignatureSubset psubset);

    @VTID(20)
    void showSignaturesPane(
        boolean rhs);

}
