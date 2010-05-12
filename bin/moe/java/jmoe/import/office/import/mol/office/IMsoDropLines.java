package mol.office  ;

import com4j.*;

@IID("{000C172C-0001-0000-C000-000000000046}")
public interface IMsoDropLines extends Com4jObject {
    @VTID(7)
    java.lang.String name();

    @VTID(8)
    void select();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.IMsoBorder border();

    @VTID(11)
    void delete();

    @VTID(12)
    mol.office.IMsoChartFormat format();

}
