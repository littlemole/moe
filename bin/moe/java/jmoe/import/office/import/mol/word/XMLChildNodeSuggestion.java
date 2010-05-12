package mol.word  ;

import com4j.*;

@IID("{A87E00E9-3AC3-4B53-ABE3-7379653D0E82}")
public interface XMLChildNodeSuggestion extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String baseName();

    @VTID(11)
    java.lang.String namespaceURI();

    @VTID(12)
    mol.word.XMLSchemaReference xmlSchemaReference();

    @VTID(13)
    mol.word.XMLNode insert(
        java.lang.Object range);

}
