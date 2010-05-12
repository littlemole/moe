package mol.excel  ;

import com4j.*;

@IID("{00024438-0001-0000-C000-000000000046}")
public interface IPhonetic extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean visible();

    @VTID(11)
    void visible(
        boolean rhs);

    @VTID(12)
    int characterType();

    @VTID(13)
    void characterType(
        int rhs);

    @VTID(14)
    int alignment();

    @VTID(15)
    void alignment(
        int rhs);

    @VTID(16)
    mol.excel.Font font();

    @VTID(17)
    java.lang.String text();

    @VTID(18)
    void text(
        java.lang.String rhs);

}
