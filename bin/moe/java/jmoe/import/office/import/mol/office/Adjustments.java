package mol.office  ;

import com4j.*;

@IID("{000C0310-0000-0000-C000-000000000046}")
public interface Adjustments extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    @DefaultMethod
    float item(
        int index);

    @VTID(12)
    @DefaultMethod
    void item(
        int index,
        float val);

}
