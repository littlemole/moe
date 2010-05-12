package mol.word  ;

import com4j.*;

@IID("{B140A023-4850-4DA6-BC5F-CC459C4507BC}")
public interface XMLNamespace extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String uri();

    @VTID(11)
    java.lang.String location(
        boolean allUsers);

    @VTID(12)
    void location(
        boolean allUsers,
        java.lang.String prop);

    @VTID(13)
    java.lang.String alias(
        boolean allUsers);

    @VTID(14)
    void alias(
        boolean allUsers,
        java.lang.String prop);

    @VTID(15)
    mol.word.XSLTransforms xslTransforms();

    @VTID(15)
    @ReturnValue(defaultPropertyThrough={mol.word.XSLTransforms.class})
    mol.word.XSLTransform xslTransforms(
        java.lang.Object index);

    @VTID(16)
    mol.word.XSLTransform defaultTransform(
        boolean allUsers);

    @VTID(17)
    void defaultTransform(
        boolean allUsers,
        mol.word.XSLTransform prop);

    @VTID(18)
    void attachToDocument(
        java.lang.Object document);

    @VTID(19)
    void delete();

}
