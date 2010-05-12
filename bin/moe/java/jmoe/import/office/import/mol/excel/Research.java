package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Research extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2751)
    java.lang.Object query(
        java.lang.String serviceID,
        java.lang.Object queryString,
        java.lang.Object queryLanguage,
        java.lang.Object useSelection,
        java.lang.Object launchQuery);

    @DISPID(2757)
    boolean isResearchService(
        java.lang.String serviceID);

    @DISPID(2758)
    java.lang.Object setLanguagePair(
        int languageFrom,
        int languageTo);

}
