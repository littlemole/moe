package mol.excel  ;

import com4j.*;

@IID("{00024460-0001-0000-C000-000000000046}")
public interface ISmartTag extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String downloadURL();

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(13)
    java.lang.String xml();

    @VTID(14)
    mol.excel.Range range();

    @VTID(15)
    void delete();

    @VTID(16)
    mol.excel.SmartTagActions smartTagActions();

    @VTID(17)
    mol.excel.CustomProperties properties();

}
