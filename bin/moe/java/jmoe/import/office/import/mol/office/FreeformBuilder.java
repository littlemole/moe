package mol.office  ;

import com4j.*;

@IID("{000C0315-0000-0000-C000-000000000046}")
public interface FreeformBuilder extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void addNodes(
        mol.office.MsoSegmentType segmentType,
        mol.office.MsoEditingType editingType,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3);

    @VTID(11)
    mol.office.Shape convertToShape();

}
