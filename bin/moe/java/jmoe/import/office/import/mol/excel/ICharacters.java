package mol.excel  ;

import com4j.*;

@IID("{00020878-0001-0000-C000-000000000046}")
public interface ICharacters extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String caption();

    @VTID(11)
    void caption(
        java.lang.String rhs);

    @VTID(12)
    int count();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(14)
    mol.excel.Font font();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object insert(
        java.lang.String string);

    @VTID(16)
    java.lang.String text();

    @VTID(17)
    void text(
        java.lang.String rhs);

    @VTID(18)
    java.lang.String phoneticCharacters();

    @VTID(19)
    void phoneticCharacters(
        java.lang.String rhs);

}
