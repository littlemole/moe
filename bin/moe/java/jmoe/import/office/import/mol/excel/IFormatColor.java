package mol.excel  ;

import com4j.*;

@IID("{00024491-0001-0000-C000-000000000046}")
public interface IFormatColor extends Com4jObject {
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
    mol.excel.XlColorIndex colorIndex();

    @VTID(13)
    void colorIndex(
        mol.excel.XlColorIndex rhs);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object themeColor();

    @VTID(15)
    void themeColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object tintAndShade();

    @VTID(17)
    void tintAndShade(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

}
