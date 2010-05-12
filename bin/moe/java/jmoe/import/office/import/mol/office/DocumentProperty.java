package mol.office  ;

import com4j.*;

@IID("{2DF8D04E-5BFA-101B-BDE5-00AA0044DE52}")
public interface DocumentProperty extends Com4jObject {
    @VTID(7)
    void parent();

    @VTID(8)
    void delete();

    @VTID(9)
    java.lang.String name(
        int lcid);

    @VTID(10)
    void name(
        int lcid,
        java.lang.String pbstrRetVal);

    @VTID(11)
    @DefaultMethod
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value(
        int lcid);

    @VTID(12)
    @DefaultMethod
    void value(
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pvargRetVal);

    @VTID(13)
    mol.office.MsoDocProperties type(
        int lcid);

    @VTID(14)
    void type(
        int lcid,
        mol.office.MsoDocProperties ptypeRetVal);

    @VTID(15)
    boolean linkToContent();

    @VTID(16)
    void linkToContent(
        boolean pfLinkRetVal);

    @VTID(17)
    java.lang.String linkSource();

    @VTID(18)
    void linkSource(
        java.lang.String pbstrSourceRetVal);

    @VTID(19)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject application();

    @VTID(20)
    int creator();

}
