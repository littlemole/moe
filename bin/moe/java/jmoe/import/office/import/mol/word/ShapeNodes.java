package mol.word  ;

import com4j.*;

@IID("{000209CE-0000-0000-C000-000000000046}")
public interface ShapeNodes extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    void delete(
        int index);

    @VTID(13)
    @DefaultMethod
    mol.word.ShapeNode item(
        java.lang.Object index);

    @VTID(14)
    void setEditingType(
        int index,
        mol.office.MsoEditingType editingType);

    @VTID(15)
    void setPosition(
        int index,
        float x1,
        float y1);

    @VTID(16)
    void setSegmentType(
        int index,
        mol.office.MsoSegmentType segmentType);

    @VTID(17)
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

}
