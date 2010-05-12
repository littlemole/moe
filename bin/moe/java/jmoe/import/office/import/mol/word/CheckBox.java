package mol.word  ;

import com4j.*;

@IID("{00020926-0000-0000-C000-000000000046}")
public interface CheckBox extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    boolean valid();

    @VTID(11)
    boolean autoSize();

    @VTID(12)
    void autoSize(
        boolean prop);

    @VTID(13)
    float size();

    @VTID(14)
    void size(
        float prop);

    @VTID(15)
    boolean _default();

    @VTID(16)
    void _default(
        boolean prop);

    @VTID(17)
    boolean value();

    @VTID(18)
    void value(
        boolean prop);

}
