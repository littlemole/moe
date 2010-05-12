package mol.word  ;

import com4j.*;

@IID("{0002095C-0000-0000-C000-000000000046}")
public interface Words extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word.Range first();

    @VTID(10)
    mol.word.Range last();

    @VTID(11)
    mol.word._Application application();

    @VTID(12)
    int creator();

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(14)
    @DefaultMethod
    mol.word.Range item(
        int index);

}
