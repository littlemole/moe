package mol.word  ;

import com4j.*;

@IID("{000209ED-0000-0000-C000-000000000046}")
public interface SmartTag extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String name();

    @VTID(8)
    java.lang.String xml();

    @VTID(9)
    mol.word.Range range();

    @VTID(10)
    java.lang.String downloadURL();

    @VTID(11)
    mol.word.CustomProperties properties();

    @VTID(11)
    @ReturnValue(defaultPropertyThrough={mol.word.CustomProperties.class})
    mol.word.CustomProperty properties(
        java.lang.Object index);

    @VTID(12)
    mol.word._Application application();

    @VTID(13)
    int creator();

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(15)
    void select();

    @VTID(16)
    void delete();

    @VTID(17)
    mol.word.SmartTagActions smartTagActions();

    @VTID(17)
    @ReturnValue(defaultPropertyThrough={mol.word.SmartTagActions.class})
    mol.word.SmartTagAction smartTagActions(
        java.lang.Object index);

    @VTID(18)
    mol.word.XMLNode xmlNode();

}
