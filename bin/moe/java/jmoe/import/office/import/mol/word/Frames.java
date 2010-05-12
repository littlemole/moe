package mol.word  ;

import com4j.*;

@IID("{0002092B-0000-0000-C000-000000000046}")
public interface Frames extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(11)
    int count();

    @VTID(12)
    @DefaultMethod
    mol.word.Frame item(
        int index);

    @VTID(13)
    mol.word.Frame add(
        mol.word.Range range);

    @VTID(14)
    void delete();

}