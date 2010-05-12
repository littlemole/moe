package mol.excel  ;

import com4j.*;

@IID("{0002443F-0001-0000-C000-000000000046}")
public interface IFreeformBuilder extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void addNodes(
        mol.office.MsoSegmentType segmentType,
        mol.office.MsoEditingType editingType,
        float x1,
        float y1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object x2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object y2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object x3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object y3);

    @VTID(11)
    mol.excel.Shape convertToShape();

}
