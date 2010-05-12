package mol.office  ;

import com4j.*;

@IID("{000C1721-0000-0000-C000-000000000046}")
public interface IMsoErrorBars extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    java.lang.String name();

    @VTID(9)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(10)
    mol.office.IMsoBorder border();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object clearFormats();

    @VTID(13)
    mol.office.XlEndStyleCap endStyle();

    @VTID(14)
    void endStyle(
        mol.office.XlEndStyleCap rhs);

    @VTID(15)
    mol.office.IMsoChartFormat format();

}
