package mol.word  ;

import com4j.*;

@IID("{47CEF4AE-DC32-4220-8AA5-19CCC0E6633A}")
public interface Reviewer extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    boolean visible();

    @VTID(11)
    @DefaultMethod
    void visible(
        boolean prop);

}
