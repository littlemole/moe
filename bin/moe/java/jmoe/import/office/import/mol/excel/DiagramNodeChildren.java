package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{000C036F-0000-0000-C000-000000000046}")
public interface DiagramNodeChildren extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(10)
    @DefaultMethod
    mol.excel.DiagramNode item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    mol.excel.DiagramNode addNode(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        mol.office.MsoDiagramNodeType nodeType);

    @VTID(12)
    void selectAll();

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(14)
    int count();

    @VTID(15)
    mol.excel.DiagramNode firstChild();

    @VTID(16)
    mol.excel.DiagramNode lastChild();

}
