package mol.word  ;

import com4j.*;

@IID("{799A6814-EA41-11D3-87CC-00105AA31A34}")
public interface MappedDataFields extends Com4jObject,Iterable<Com4jObject> {
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
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    @DefaultMethod
    mol.word.MappedDataField item(
        mol.word.WdMappedDataFields index);

}
