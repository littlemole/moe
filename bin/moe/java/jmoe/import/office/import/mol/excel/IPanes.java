package mol.excel  ;

import com4j.*;

@IID("{00020894-0001-0000-C000-000000000046}")
public interface IPanes extends Com4jObject {
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
    mol.excel.Pane item(
        int index);

    @VTID(12)
    @DefaultMethod
    mol.excel.Pane _Default(
        int index);

}
