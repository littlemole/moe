package mol.word  ;

import com4j.*;

@IID("{00020974-0000-0000-C000-000000000046}")
public interface TextColumn extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    float width();

    @VTID(11)
    void width(
        float prop);

    @VTID(12)
    float spaceAfter();

    @VTID(13)
    void spaceAfter(
        float prop);

}
