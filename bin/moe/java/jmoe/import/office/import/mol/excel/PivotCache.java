package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface PivotCache extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1427)
    @PropGet
    boolean backgroundQuery();

    @DISPID(1427)
    @PropPut
    void backgroundQuery(
        boolean rhs);

    @DISPID(1432)
    @PropGet
    java.lang.Object connection();

    @DISPID(1432)
    @PropPut
    void connection(
        java.lang.Object rhs);

    @DISPID(1477)
    @PropGet
    boolean enableRefresh();

    @DISPID(1477)
    @PropPut
    void enableRefresh(
        boolean rhs);

    @DISPID(486)
    @PropGet
    int index();

    @DISPID(372)
    @PropGet
    int memoryUsed();

    @DISPID(1428)
    @PropGet
    boolean optimizeCache();

    @DISPID(1428)
    @PropPut
    void optimizeCache(
        boolean rhs);

    @DISPID(1478)
    @PropGet
    int recordCount();

    @DISPID(1417)
    void refresh();

    @DISPID(696)
    @PropGet
    java.util.Date refreshDate();

    @DISPID(697)
    @PropGet
    java.lang.String refreshName();

    @DISPID(1479)
    @PropGet
    boolean refreshOnFileOpen();

    @DISPID(1479)
    @PropPut
    void refreshOnFileOpen(
        boolean rhs);

    @DISPID(1480)
    @PropGet
    java.lang.Object sql();

    @DISPID(1480)
    @PropPut
    void sql(
        java.lang.Object rhs);

    @DISPID(1481)
    @PropGet
    boolean savePassword();

    @DISPID(1481)
    @PropPut
    void savePassword(
        boolean rhs);

    @DISPID(686)
    @PropGet
    java.lang.Object sourceData();

    @DISPID(686)
    @PropPut
    void sourceData(
        java.lang.Object rhs);

    @DISPID(1829)
    @PropGet
    java.lang.Object commandText();

    @DISPID(1829)
    @PropPut
    void commandText(
        java.lang.Object rhs);

    @DISPID(1830)
    @PropGet
    mol.excel.XlCmdType commandType();

    @DISPID(1830)
    @PropPut
    void commandType(
        mol.excel.XlCmdType rhs);

    @DISPID(1831)
    @PropGet
    mol.excel.XlQueryType queryType();

    @DISPID(1832)
    @PropGet
    boolean maintainConnection();

    @DISPID(1832)
    @PropPut
    void maintainConnection(
        boolean rhs);

    @DISPID(1833)
    @PropGet
    int refreshPeriod();

    @DISPID(1833)
    @PropPut
    void refreshPeriod(
        int rhs);

    @DISPID(1165)
    @PropGet
    com4j.Com4jObject recordset();

    @DISPID(1165)
    @PropPut
    void recordset(
        com4j.Com4jObject rhs);

    @DISPID(1834)
    void resetTimer();

    @DISPID(1835)
    @PropGet
    java.lang.Object localConnection();

    @DISPID(1835)
    @PropPut
    void localConnection(
        java.lang.Object rhs);

    @DISPID(1836)
    mol.excel.PivotTable createPivotTable(
        java.lang.Object tableDestination,
        java.lang.Object tableName,
        java.lang.Object readData,
        java.lang.Object defaultVersion);

    @DISPID(1837)
    @PropGet
    boolean useLocalConnection();

    @DISPID(1837)
    @PropPut
    void useLocalConnection(
        boolean rhs);

    @DISPID(2074)
    @PropGet
    com4j.Com4jObject adoConnection();

    @DISPID(2075)
    @PropGet
    boolean isConnected();

    @DISPID(2076)
    void makeConnection();

    @DISPID(2077)
    @PropGet
    boolean olap();

    @DISPID(685)
    @PropGet
    mol.excel.XlPivotTableSourceType sourceType();

    @DISPID(2078)
    @PropGet
    mol.excel.XlPivotTableMissingItems missingItemsLimit();

    @DISPID(2078)
    @PropPut
    void missingItemsLimit(
        mol.excel.XlPivotTableMissingItems rhs);

    @DISPID(2079)
    @PropGet
    java.lang.String sourceConnectionFile();

    @DISPID(2079)
    @PropPut
    void sourceConnectionFile(
        java.lang.String rhs);

    @DISPID(2080)
    @PropGet
    java.lang.String sourceDataFile();

    @DISPID(2081)
    @PropGet
    mol.excel.XlRobustConnect robustConnect();

    @DISPID(2081)
    @PropPut
    void robustConnect(
        mol.excel.XlRobustConnect rhs);

    @DISPID(2082)
    void saveAsODC(
        java.lang.String odcFileName,
        java.lang.Object description,
        java.lang.Object keywords);

    @DISPID(2544)
    @PropGet
    mol.excel.WorkbookConnection workbookConnection();

    @DISPID(392)
    @PropGet
    mol.excel.XlPivotTableVersionList version();

    @DISPID(2545)
    @PropGet
    boolean upgradeOnRefresh();

    @DISPID(2545)
    @PropPut
    void upgradeOnRefresh(
        boolean rhs);

}
