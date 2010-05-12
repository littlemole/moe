package mol.word  ;

import com4j.*;

@IID("{656BBED7-E82D-4B0A-8F97-EC742BA11FFA}")
public interface XMLNamespaces extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.XMLNamespace item(
        java.lang.Object index);

    @VTID(13)
    mol.word.XMLNamespace add(
        java.lang.String path,
        java.lang.Object namespaceURI,
        java.lang.Object alias,
        boolean installForAllUsers);

    @VTID(14)
    void installManifest(
        java.lang.String path,
        boolean installForAllUsers);

}
