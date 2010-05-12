package mol.word  ;

import com4j.*;

@IID("{07B7CC7E-E66C-11D3-9454-00105AA31A08}")
public interface StyleSheets extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.StyleSheet item(
        java.lang.Object index);

    @VTID(13)
    mol.word.StyleSheet add(
        java.lang.String fileName,
        mol.word.WdStyleSheetLinkType linkType,
        java.lang.String title,
        mol.word.WdStyleSheetPrecedence precedence);

}
