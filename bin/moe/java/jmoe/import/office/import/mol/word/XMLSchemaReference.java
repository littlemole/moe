package mol.word  ;

import com4j.*;

@IID("{FE0971F0-5E60-4985-BCDA-95CB0B8E0308}")
public interface XMLSchemaReference extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String namespaceURI();

    @VTID(11)
    java.lang.String location();

    @VTID(12)
    void delete();

    @VTID(13)
    void reload();

}
