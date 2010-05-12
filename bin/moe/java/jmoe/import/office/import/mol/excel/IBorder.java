package mol.excel  ;

import com4j.*;

@IID("{00020854-0001-0000-C000-000000000046}")
public interface IBorder extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object color();

    @VTID(11)
    void color(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object colorIndex();

    @VTID(13)
    void colorIndex(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object lineStyle();

    @VTID(15)
    void lineStyle(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object weight();

    @VTID(17)
    void weight(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object themeColor();

    @VTID(19)
    void themeColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object tintAndShade();

    @VTID(21)
    void tintAndShade(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

}
