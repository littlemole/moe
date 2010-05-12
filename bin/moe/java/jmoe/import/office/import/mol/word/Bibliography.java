package mol.word  ;

import com4j.*;

@IID("{3834F60F-EE8C-455D-A441-D766675D6D3B}")
public interface Bibliography extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.Sources sources();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.word.Sources.class})
    mol.word.Source sources(
        int index);

    @VTID(11)
    java.lang.String bibliographyStyle();

    @VTID(12)
    void bibliographyStyle(
        java.lang.String prop);

    @VTID(13)
    java.lang.String generateUniqueTag();

}
