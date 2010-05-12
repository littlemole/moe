package mol.office  ;

import com4j.*;

@IID("{000C172E-0000-0000-C000-000000000046}")
public interface IMsoHiLoLines extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    java.lang.String name();

    @VTID(9)
    void select();

    @VTID(10)
    mol.office.IMsoBorder border();

    @VTID(11)
    void delete();

    @VTID(12)
    mol.office.IMsoChartFormat format();

}
