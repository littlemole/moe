package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{000C036E-0000-0000-C000-000000000046}")
public interface DiagramNodes extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(10)
    @DefaultMethod
    mol.excel.DiagramNode item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    void selectAll();

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(13)
    int count();

}
