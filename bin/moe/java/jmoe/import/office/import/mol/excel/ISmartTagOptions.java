package mol.excel  ;

import com4j.*;

@IID("{00024464-0001-0000-C000-000000000046}")
public interface ISmartTagOptions extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.XlSmartTagDisplayMode displaySmartTags();

    @VTID(11)
    void displaySmartTags(
        mol.excel.XlSmartTagDisplayMode rhs);

    @VTID(12)
    boolean embedSmartTags();

    @VTID(13)
    void embedSmartTags(
        boolean rhs);

}
