package mol.word  ;

import com4j.*;

@IID("{873E774B-926A-4CB1-878D-635A45187595}")
public interface OMaths extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    int count();

    @VTID(12)
    @DefaultMethod
    mol.word.OMath item(
        int index);

    @VTID(13)
    void linearize();

    @VTID(14)
    void buildUp();

    @VTID(15)
    mol.word.Range add(
        mol.word.Range range);

}
