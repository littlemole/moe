package mol.excel  ;

import com4j.*;

@IID("{000208CE-0001-0000-C000-000000000046}")
public interface IErrorBars extends Com4jObject {
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
    java.lang.Object delete();

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(15)
    mol.excel.XlEndStyleCap endStyle();

    @VTID(16)
    void endStyle(
        mol.excel.XlEndStyleCap rhs);

    @VTID(17)
    mol.excel.ChartFormat format();

}