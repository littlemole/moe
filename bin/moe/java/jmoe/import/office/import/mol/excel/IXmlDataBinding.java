package mol.excel  ;

import com4j.*;

@IID("{00024478-0001-0000-C000-000000000046}")
public interface IXmlDataBinding extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(11)
    mol.excel.XlXmlImportResult refresh();

    @VTID(12)
    void loadSettings(
        java.lang.String url);

    @VTID(13)
    void clearSettings();

    @VTID(14)
    java.lang.String sourceUrl();

}
