package mol.excel  ;

import com4j.*;

@IID("{00020855-0001-0000-C000-000000000046}")
public interface IBorders extends Com4jObject,Iterable<Com4jObject> {
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
    int count();

    @VTID(15)
    mol.excel.Border item(
        mol.excel.XlBordersIndex index);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object lineStyle();

    @VTID(17)
    void lineStyle(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(18)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value();

    @VTID(20)
    void value(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object weight();

    @VTID(22)
    void weight(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(23)
    @DefaultMethod
    mol.excel.Border _Default(
        mol.excel.XlBordersIndex index);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object themeColor();

    @VTID(25)
    void themeColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object tintAndShade();

    @VTID(27)
    void tintAndShade(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

}
