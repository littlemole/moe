package mol.word  ;

import com4j.*;

@IID("{B923FDE0-F08C-11D3-91B0-00105A0A19FD}")
public interface CustomProperty extends Com4jObject {
    @VTID(7)
    java.lang.String name();

    @VTID(8)
    @DefaultMethod
    java.lang.String value();

    @VTID(9)
    @DefaultMethod
    void value(
        java.lang.String prop);

    @VTID(10)
    mol.word._Application application();

    @VTID(11)
    int creator();

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(13)
    void delete();

}
