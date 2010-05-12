package mol.excel  ;

import com4j.*;

@IID("{000208C8-0001-0000-C000-000000000046}")
public interface IWalls extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(12)
    mol.excel.Border border();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(14)
    mol.excel.Interior interior();

    @VTID(15)
    mol.excel.ChartFillFormat fill();

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object pictureType();

    @VTID(17)
    void pictureType(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(18)
    void paste();

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object pictureUnit();

    @VTID(20)
    void pictureUnit(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(21)
    int thickness();

    @VTID(22)
    void thickness(
        int rhs);

    @VTID(23)
    mol.excel.ChartFormat format();

}
