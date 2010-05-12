package mol.office  ;

import com4j.*;

@IID("{000C1716-0000-0000-C000-000000000046}")
public interface IMsoFloor extends Com4jObject {
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
    java.lang.Object clearFormats();

    @VTID(12)
    mol.office.IMsoInterior interior();

    @VTID(13)
    mol.office.ChartFillFormat fill();

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object pictureType();

    @VTID(15)
    void pictureType(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pvar);

    @VTID(16)
    void paste();

    @VTID(17)
    int thickness();

    @VTID(18)
    void thickness(
        int rhs);

    @VTID(19)
    mol.office.IMsoChartFormat format();

}
