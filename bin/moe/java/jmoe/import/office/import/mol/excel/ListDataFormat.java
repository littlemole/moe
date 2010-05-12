package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ListDataFormat extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    mol.excel.XlListDataType _Default();

    @DISPID(2348)
    @PropGet
    java.lang.Object choices();

    @DISPID(2349)
    @PropGet
    int decimalPlaces();

    @DISPID(2350)
    @PropGet
    java.lang.Object defaultValue();

    @DISPID(2351)
    @PropGet
    boolean isPercent();

    @DISPID(2352)
    @PropGet
    int lcid();

    @DISPID(2353)
    @PropGet
    int maxCharacters();

    @DISPID(2354)
    @PropGet
    java.lang.Object maxNumber();

    @DISPID(2355)
    @PropGet
    java.lang.Object minNumber();

    @DISPID(2356)
    @PropGet
    boolean required();

    @DISPID(108)
    @PropGet
    mol.excel.XlListDataType type();

    @DISPID(296)
    @PropGet
    boolean readOnly();

    @DISPID(2357)
    @PropGet
    boolean allowFillIn();

}
