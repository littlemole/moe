package mol.excel  ;

import com4j.*;

@IID("{00024455-0001-0000-C000-000000000046}")
public interface ICalculatedMember extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    java.lang.String formula();

    @VTID(12)
    java.lang.String sourceName();

    @VTID(13)
    int solveOrder();

    @VTID(14)
    boolean isValid();

    @VTID(15)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(16)
    void delete();

    @VTID(17)
    mol.excel.XlCalculatedMemberType type();

}
