package mol.office  ;

import com4j.*;

@IID("{000C0340-0000-0000-C000-000000000046}")
public interface Scripts extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    @DefaultMethod
    mol.office.Script item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    mol.office.Script add(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject anchor,
        mol.office.MsoScriptLocation location,
        mol.office.MsoScriptLanguage language,
        java.lang.String id,
        java.lang.String extended,
        java.lang.String scriptText);

    @VTID(14)
    void delete();

}
