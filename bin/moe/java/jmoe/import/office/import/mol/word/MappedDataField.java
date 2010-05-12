package mol.word  ;

import com4j.*;

@IID("{5D311669-EA51-11D3-87CC-00105AA31A34}")
public interface MappedDataField extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int index();

    @VTID(11)
    java.lang.String dataFieldName();

    @VTID(12)
    @DefaultMethod
    java.lang.String name();

    @VTID(13)
    java.lang.String value();

    @VTID(14)
    int dataFieldIndex();

    @VTID(15)
    void dataFieldIndex(
        int prop);

}
