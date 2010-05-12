package mol.excel  ;

import com4j.*;

@IID("{00020895-0001-0000-C000-000000000046}")
public interface IPane extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean activate();

    @VTID(11)
    int index();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object largeScroll(
        @MarshalAs(NativeType.VARIANT) java.lang.Object down,
        @MarshalAs(NativeType.VARIANT) java.lang.Object up,
        @MarshalAs(NativeType.VARIANT) java.lang.Object toRight,
        @MarshalAs(NativeType.VARIANT) java.lang.Object toLeft);

    @VTID(13)
    int scrollColumn();

    @VTID(14)
    void scrollColumn(
        int rhs);

    @VTID(15)
    int scrollRow();

    @VTID(16)
    void scrollRow(
        int rhs);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object smallScroll(
        @MarshalAs(NativeType.VARIANT) java.lang.Object down,
        @MarshalAs(NativeType.VARIANT) java.lang.Object up,
        @MarshalAs(NativeType.VARIANT) java.lang.Object toRight,
        @MarshalAs(NativeType.VARIANT) java.lang.Object toLeft);

    @VTID(18)
    mol.excel.Range visibleRange();

    @VTID(19)
    void scrollIntoView(
        int left,
        int top,
        int width,
        int height,
        @MarshalAs(NativeType.VARIANT) java.lang.Object start);

    @VTID(20)
    int pointsToScreenPixelsX(
        int points);

    @VTID(21)
    int pointsToScreenPixelsY(
        int points);

}
