package mol.office  ;

import com4j.*;

@IID("{000C0318-0000-0000-C000-000000000046}")
public interface ShapeNode extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.MsoEditingType editingType();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object points();

    @VTID(12)
    mol.office.MsoSegmentType segmentType();

}
