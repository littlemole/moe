package mol.word  ;

import com4j.*;

@IID("{000209EF-0000-0000-C000-000000000046}")
public interface StyleSheet extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String fullName();

    @VTID(11)
    int index();

    @VTID(12)
    java.lang.String name();

    @VTID(13)
    java.lang.String path();

    @VTID(14)
    mol.word.WdStyleSheetLinkType type();

    @VTID(15)
    void type(
        mol.word.WdStyleSheetLinkType prop);

    @VTID(16)
    java.lang.String title();

    @VTID(17)
    void title(
        java.lang.String prop);

    @VTID(18)
    void move(
        mol.word.WdStyleSheetPrecedence precedence);

    @VTID(19)
    void delete();

}
