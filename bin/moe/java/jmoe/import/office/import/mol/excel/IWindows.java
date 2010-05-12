package mol.excel  ;

import com4j.*;

@IID("{00020892-0001-0000-C000-000000000046}")
public interface IWindows extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object arrange(
        mol.excel.XlArrangeStyle arrangeStyle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activeWorkbook,
        @MarshalAs(NativeType.VARIANT) java.lang.Object syncHorizontal,
        @MarshalAs(NativeType.VARIANT) java.lang.Object syncVertical);

    @VTID(11)
    int count();

    @VTID(12)
    mol.excel.Window item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(14)
    @DefaultMethod
    mol.excel.Window _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(15)
    boolean compareSideBySideWith(
        @MarshalAs(NativeType.VARIANT) java.lang.Object windowName);

    @VTID(16)
    boolean breakSideBySide();

    @VTID(17)
    boolean syncScrollingSideBySide();

    @VTID(18)
    void syncScrollingSideBySide(
        boolean rhs);

    @VTID(19)
    void resetPositionsSideBySide();

}
