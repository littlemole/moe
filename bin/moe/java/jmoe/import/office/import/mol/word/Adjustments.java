package mol.word  ;

import com4j.*;

@IID("{000209C4-0000-0000-C000-000000000046}")
public interface Adjustments extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

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
        float prop);

}
