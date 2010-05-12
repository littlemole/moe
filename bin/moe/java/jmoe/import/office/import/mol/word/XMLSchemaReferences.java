package mol.word  ;

import com4j.*;

@IID("{356B06EC-4908-42A4-81FC-4B5A51F3483B}")
public interface XMLSchemaReferences extends Com4jObject,Iterable<Com4jObject> {
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
    boolean automaticValidation();

    @VTID(13)
    void automaticValidation(
        boolean prop);

    @VTID(14)
    boolean allowSaveAsXMLWithoutValidation();

    @VTID(15)
    void allowSaveAsXMLWithoutValidation(
        boolean prop);

    @VTID(16)
    boolean hideValidationErrors();

    @VTID(17)
    void hideValidationErrors(
        boolean prop);

    @VTID(18)
    boolean ignoreMixedContent();

    @VTID(19)
    void ignoreMixedContent(
        boolean prop);

    @VTID(20)
    boolean showPlaceholderText();

    @VTID(21)
    void showPlaceholderText(
        boolean prop);

    @VTID(22)
    @DefaultMethod
    mol.word.XMLSchemaReference item(
        java.lang.Object index);

    @VTID(23)
    void validate();

    @VTID(24)
    mol.word.XMLSchemaReference add(
        java.lang.Object namespaceURI,
        java.lang.Object alias,
        java.lang.Object fileName,
        boolean installForAllUsers);

}
