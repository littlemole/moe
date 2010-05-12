package mol.office  ;

import com4j.*;

@IID("{000C1725-0000-0000-C000-000000000046}")
public interface GridLines extends Com4jObject {
    @VTID(7)
    java.lang.String name();

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object select();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.IMsoBorder border();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(12)
    mol.office.IMsoChartFormat format();

}
