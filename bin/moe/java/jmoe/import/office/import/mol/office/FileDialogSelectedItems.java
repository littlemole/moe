package mol.office  ;

import com4j.*;

@IID("{000C0363-0000-0000-C000-000000000046}")
public interface FileDialogSelectedItems extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(11)
    int count();

    @VTID(12)
    @DefaultMethod
    java.lang.String item(
        int index);

}
