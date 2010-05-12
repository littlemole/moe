package mol.excel  ;

import com4j.*;

@IID("{0002441C-0001-0000-C000-000000000046}")
public interface IPivotCache extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean backgroundQuery();

    @VTID(11)
    void backgroundQuery(
        boolean rhs);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object connection();

    @VTID(13)
    void connection(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(14)
    boolean enableRefresh();

    @VTID(15)
    void enableRefresh(
        boolean rhs);

    @VTID(16)
    int index();

    @VTID(17)
    int memoryUsed();

    @VTID(18)
    boolean optimizeCache();

    @VTID(19)
    void optimizeCache(
        boolean rhs);

    @VTID(20)
    int recordCount();

    @VTID(21)
    void refresh();

    @VTID(22)
    java.util.Date refreshDate();

    @VTID(23)
    java.lang.String refreshName();

    @VTID(24)
    boolean refreshOnFileOpen();

    @VTID(25)
    void refreshOnFileOpen(
        boolean rhs);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object sql();

    @VTID(27)
    void sql(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(28)
    boolean savePassword();

    @VTID(29)
    void savePassword(
        boolean rhs);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object sourceData();

    @VTID(31)
    void sourceData(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(32)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object commandText();

    @VTID(33)
    void commandText(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(34)
    mol.excel.XlCmdType commandType();

    @VTID(35)
    void commandType(
        mol.excel.XlCmdType rhs);

    @VTID(36)
    mol.excel.XlQueryType queryType();

    @VTID(37)
    boolean maintainConnection();

    @VTID(38)
    void maintainConnection(
        boolean rhs);

    @VTID(39)
    int refreshPeriod();

    @VTID(40)
    void refreshPeriod(
        int rhs);

    @VTID(41)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject recordset();

    @VTID(42)
    void recordset(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject rhs);

    @VTID(43)
    void resetTimer();

    @VTID(44)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object localConnection();

    @VTID(45)
    void localConnection(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(46)
    mol.excel.PivotTable createPivotTable(
        @MarshalAs(NativeType.VARIANT) java.lang.Object tableDestination,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tableName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readData,
        @MarshalAs(NativeType.VARIANT) java.lang.Object defaultVersion);

    @VTID(47)
    boolean useLocalConnection();

    @VTID(48)
    void useLocalConnection(
        boolean rhs);

    @VTID(49)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject adoConnection();

    @VTID(50)
    boolean isConnected();

    @VTID(51)
    void makeConnection();

    @VTID(52)
    boolean olap();

    @VTID(53)
    mol.excel.XlPivotTableSourceType sourceType();

    @VTID(54)
    mol.excel.XlPivotTableMissingItems missingItemsLimit();

    @VTID(55)
    void missingItemsLimit(
        mol.excel.XlPivotTableMissingItems rhs);

    @VTID(56)
    java.lang.String sourceConnectionFile();

    @VTID(57)
    void sourceConnectionFile(
        java.lang.String rhs);

    @VTID(58)
    java.lang.String sourceDataFile();

    @VTID(59)
    mol.excel.XlRobustConnect robustConnect();

    @VTID(60)
    void robustConnect(
        mol.excel.XlRobustConnect rhs);

    @VTID(61)
    void saveAsODC(
        java.lang.String odcFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object description,
        @MarshalAs(NativeType.VARIANT) java.lang.Object keywords);

    @VTID(62)
    mol.excel.WorkbookConnection workbookConnection();

    @VTID(63)
    mol.excel.XlPivotTableVersionList version();

    @VTID(64)
    boolean upgradeOnRefresh();

    @VTID(65)
    void upgradeOnRefresh(
        boolean rhs);

}
