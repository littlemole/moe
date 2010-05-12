package mol.excel  ;

import com4j.*;

@IID("{00024447-0001-0000-C000-000000000046}")
public interface IPhonetics extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    int start();

    @VTID(12)
    int length();

    @VTID(13)
    boolean visible();

    @VTID(14)
    void visible(
        boolean rhs);

    @VTID(15)
    int characterType();

    @VTID(16)
    void characterType(
        int rhs);

    @VTID(17)
    int alignment();

    @VTID(18)
    void alignment(
        int rhs);

    @VTID(19)
    mol.excel.Font font();

    @VTID(20)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        int index);

    @VTID(21)
    void delete();

    @VTID(22)
    void add(
        int start,
        int length,
        java.lang.String text);

    @VTID(23)
    java.lang.String text();

    @VTID(24)
    void text(
        java.lang.String rhs);

    @VTID(25)
    @DefaultMethod
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject _Default(
        int index);

    @VTID(26)
    java.util.Iterator<Com4jObject> iterator();

}
