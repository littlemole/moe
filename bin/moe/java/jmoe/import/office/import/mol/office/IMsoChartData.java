package mol.office  ;

import com4j.*;

@IID("{000C172F-0000-0000-C000-000000000046}")
public interface IMsoChartData extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject workbook();

    @VTID(8)
    void activate();

    @VTID(9)
    boolean isLinked();

    @VTID(10)
    void breakLink();

}
