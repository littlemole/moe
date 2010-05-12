package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ODBCConnection extends Com4jObject {
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

    @DISPID(686)
    @PropGet
    java.lang.Object sourceData();

    @DISPID(686)
    @PropPut
    void sourceData(
        java.lang.Object rhs);

    @DISPID(2080)
    @PropGet
    java.lang.String sourceDataFile();

    @DISPID(2080)
    @PropPut
    void sourceDataFile(
        java.lang.String rhs);

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

}
