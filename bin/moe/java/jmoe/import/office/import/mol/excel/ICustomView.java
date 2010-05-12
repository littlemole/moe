package mol.excel  ;

import com4j.*;

@IID("{00024423-0001-0000-C000-000000000046}")
public interface ICustomView extends Com4jObject {
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
    boolean printSettings();

    @VTID(12)
    boolean rowColSettings();

    @VTID(13)
    void show();

    @VTID(14)
    void delete();

}
