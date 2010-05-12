package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface OLEDBConnection extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2074)
    @PropGet
    com4j.Com4jObject adoConnection();

    @DISPID(1427)
    @PropGet
    boolean backgroundQuery();

    @DISPID(1427)
    @PropPut
    void backgroundQuery(
        boolean rhs);

    @DISPID(1589)
    void cancelRefresh();

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

    @DISPID(1835)
    @PropGet
    java.lang.Object localConnection();

    @DISPID(1835)
    @PropPut
    void localConnection(
        java.lang.Object rhs);

    @DISPID(1832)
    @PropGet
    boolean maintainConnection();

    @DISPID(1832)
    @PropPut
    void maintainConnection(
        boolean rhs);

    @DISPID(2076)
    void makeConnection();

    @DISPID(1417)
    void refresh();

    @DISPID(696)
    @PropGet
    java.util.Date refreshDate();

    @DISPID(1587)
    @PropGet
    boolean refreshing();

    @DISPID(1479)
    @PropGet
    boolean refreshOnFileOpen();

    @DISPID(1479)
    @PropPut
    void refreshOnFileOpen(
        boolean rhs);

    @DISPID(1833)
    @PropGet
    int refreshPeriod();

    @DISPID(1833)
    @PropPut
    void refreshPeriod(
        int rhs);

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

    @DISPID(1481)
    @PropGet
    boolean savePassword();

    @DISPID(1481)
    @PropPut
    void savePassword(
        boolean rhs);

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

    @DISPID(2080)
    @PropPut
    void sourceDataFile(
        java.lang.String rhs);

    @DISPID(2077)
    @PropGet
    boolean olap();

    @DISPID(1837)
    @PropGet
    boolean useLocalConnection();

    @DISPID(1837)
    @PropPut
    void useLocalConnection(
        boolean rhs);

    @DISPID(2703)
    @PropGet
    int maxDrillthroughRecords();

    @DISPID(2703)
    @PropPut
    void maxDrillthroughRecords(
        int rhs);

    @DISPID(2075)
    @PropGet
    boolean isConnected();

    @DISPID(2704)
    @PropGet
    mol.excel.XlCredentialsMethod serverCredentialsMethod();

    @DISPID(2704)
    @PropPut
    void serverCredentialsMethod(
        mol.excel.XlCredentialsMethod rhs);

    @DISPID(2705)
    @PropGet
    java.lang.String serverSSOApplicationID();

    @DISPID(2705)
    @PropPut
    void serverSSOApplicationID(
        java.lang.String rhs);

    @DISPID(2706)
    @PropGet
    boolean alwaysUseConnectionFile();

    @DISPID(2706)
    @PropPut
    void alwaysUseConnectionFile(
        boolean rhs);

    @DISPID(2707)
    @PropGet
    boolean serverFillColor();

    @DISPID(2707)
    @PropPut
    void serverFillColor(
        boolean rhs);

    @DISPID(2708)
    @PropGet
    boolean serverFontStyle();

    @DISPID(2708)
    @PropPut
    void serverFontStyle(
        boolean rhs);

    @DISPID(2709)
    @PropGet
    boolean serverNumberFormat();

    @DISPID(2709)
    @PropPut
    void serverNumberFormat(
        boolean rhs);

    @DISPID(2710)
    @PropGet
    boolean serverTextColor();

    @DISPID(2710)
    @PropPut
    void serverTextColor(
        boolean rhs);

    @DISPID(2711)
    @PropGet
    boolean retrieveInOfficeUILang();

    @DISPID(2711)
    @PropPut
    void retrieveInOfficeUILang(
        boolean rhs);

}
