package mol.office  ;

import com4j.*;

@IID("{2DF8D04D-5BFA-101B-BDE5-00AA0044DE52}")
public interface DocumentProperties extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    void parent();

    @VTID(8)
    @DefaultMethod
    mol.office.DocumentProperty item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(9)
    int count();

    @VTID(10)
    mol.office.DocumentProperty add(
        java.lang.String name,
        boolean linkToContent,
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object value,
        @MarshalAs(NativeType.VARIANT) java.lang.Object linkSource,
        int lcid);

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject application();

    @VTID(13)
    int creator();

}
