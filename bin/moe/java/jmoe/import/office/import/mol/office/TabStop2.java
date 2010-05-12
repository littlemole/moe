package mol.office  ;

import com4j.*;

@IID("{000C03BB-0000-0000-C000-000000000046}")
public interface TabStop2 extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void clear();

    @VTID(11)
    float position();

    @VTID(12)
    void position(
        float position);

    @VTID(13)
    mol.office.MsoTabStopType type();

    @VTID(14)
    void type(
        mol.office.MsoTabStopType type);

}
