package mol.excel  ;

import com4j.*;

@IID("{00024462-0001-0000-C000-000000000046}")
public interface ISmartTagRecognizer extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean enabled();

    @VTID(11)
    void enabled(
        boolean rhs);

    @VTID(12)
    java.lang.String progID();

    @VTID(13)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(14)
    java.lang.String fullName();

}
