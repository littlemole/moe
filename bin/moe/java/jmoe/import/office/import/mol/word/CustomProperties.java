package mol.word  ;

import com4j.*;

@IID("{B923FDE1-F08C-11D3-91B0-00105A0A19FD}")
public interface CustomProperties extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word._Application application();

    @VTID(10)
    int creator();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    @DefaultMethod
    mol.word.CustomProperty item(
        java.lang.Object index);

    @VTID(13)
    mol.word.CustomProperty add(
        java.lang.String name,
        java.lang.String value);

}
