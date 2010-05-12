package mol.office  ;

import com4j.*;

@IID("{000C1723-0000-0000-C000-000000000046}")
public interface IMsoLeaderLines extends Com4jObject {
    @VTID(7)
    void select();

    @VTID(8)
    mol.office.IMsoBorder border();

    @VTID(9)
    void delete();

    @VTID(10)
    mol.office.IMsoChartFormat format();

}
