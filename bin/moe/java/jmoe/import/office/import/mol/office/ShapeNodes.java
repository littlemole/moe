package mol.office  ;

import com4j.*;

@IID("{000C0319-0000-0000-C000-000000000046}")
public interface ShapeNodes extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    mol.office.ShapeNode item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(13)
    void delete(
        int index);

    @VTID(14)
    void insert(
        int index,
        mol.office.MsoSegmentType segmentType,
        mol.office.MsoEditingType editingType,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3);

    @VTID(15)
    void setEditingType(
        int index,
        mol.office.MsoEditingType editingType);

    @VTID(16)
    void setPosition(
        int index,
        float x1,
        float y1);

    @VTID(17)
    void setSegmentType(
        int index,
        mol.office.MsoSegmentType segmentType);

}
