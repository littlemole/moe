package mol.excel  ;

import com4j.*;

@IID("{000244AD-0001-0000-C000-000000000046}")
public interface IColorStop extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void delete();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object color();

    @VTID(12)
    void color(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(13)
    int themeColor();

    @VTID(14)
    void themeColor(
        int rhs);

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object tintAndShade();

    @VTID(16)
    void tintAndShade(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(17)
    double position();

    @VTID(18)
    void position(
        double rhs);

}
