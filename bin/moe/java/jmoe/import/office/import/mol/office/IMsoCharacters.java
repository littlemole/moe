package mol.office  ;

import com4j.*;

@IID("{000C1731-0000-0000-C000-000000000046}")
public interface IMsoCharacters extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(8)
    java.lang.String caption();

    @VTID(9)
    void caption(
        java.lang.String rhs);

    @VTID(10)
    int count();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(12)
    mol.office.ChartFont font();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object insert(
        java.lang.String bstr);

    @VTID(14)
    java.lang.String text();

    @VTID(15)
    void text(
        java.lang.String rhs);

    @VTID(16)
    java.lang.String phoneticCharacters();

    @VTID(17)
    void phoneticCharacters(
        java.lang.String rhs);

}
