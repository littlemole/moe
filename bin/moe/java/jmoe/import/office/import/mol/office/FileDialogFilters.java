package mol.office  ;

import com4j.*;

@IID("{000C0365-0000-0000-C000-000000000046}")
public interface FileDialogFilters extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(11)
    int count();

    @VTID(12)
    @DefaultMethod
    mol.office.FileDialogFilter item(
        int index);

    @VTID(13)
    void delete(
        @MarshalAs(NativeType.VARIANT) java.lang.Object filter);

    @VTID(14)
    void clear();

    @VTID(15)
    mol.office.FileDialogFilter add(
        java.lang.String description,
        java.lang.String extensions,
        @MarshalAs(NativeType.VARIANT) java.lang.Object position);

}
