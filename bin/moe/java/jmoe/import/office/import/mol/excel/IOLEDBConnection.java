package mol.excel  ;

import com4j.*;

@IID("{0002448D-0001-0000-C000-000000000046}")
public interface IOLEDBConnection extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject adoConnection();

    @VTID(11)
    boolean backgroundQuery();

    @VTID(12)
    void backgroundQuery(
        boolean rhs);

    @VTID(13)
    void cancelRefresh();

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object commandText();

    @VTID(15)
    void commandText(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(16)
    mol.excel.XlCmdType commandType();

    @VTID(17)
    void commandType(
        mol.excel.XlCmdType rhs);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object connection();

    @VTID(19)
    void connection(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(20)
    boolean enableRefresh();

    @VTID(21)
    void enableRefresh(
        boolean rhs);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object localConnection();

    @VTID(23)
    void localConnection(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(24)
    boolean maintainConnection();

    @VTID(25)
    void maintainConnection(
        boolean rhs);

    @VTID(26)
    void makeConnection();

    @VTID(27)
    void refresh();

    @VTID(28)
    java.util.Date refreshDate();

    @VTID(29)
    boolean refreshing();

    @VTID(30)
    boolean refreshOnFileOpen();

    @VTID(31)
    void refreshOnFileOpen(
        boolean rhs);

    @VTID(32)
    int refreshPeriod();

    @VTID(33)
    void refreshPeriod(
        int rhs);

    @VTID(34)
    mol.excel.XlRobustConnect robustConnect();

    @VTID(35)
    void robustConnect(
        mol.excel.XlRobustConnect rhs);

    @VTID(36)
    void saveAsODC(
        java.lang.String odcFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object description,
        @MarshalAs(NativeType.VARIANT) java.lang.Object keywords);

    @VTID(37)
    boolean savePassword();

    @VTID(38)
    void savePassword(
        boolean rhs);

    @VTID(39)
    java.lang.String sourceConnectionFile();

    @VTID(40)
    void sourceConnectionFile(
        java.lang.String rhs);

    @VTID(41)
    java.lang.String sourceDataFile();

    @VTID(42)
    void sourceDataFile(
        java.lang.String rhs);

    @VTID(43)
    boolean olap();

    @VTID(44)
    boolean useLocalConnection();

    @VTID(45)
    void useLocalConnection(
        boolean rhs);

    @VTID(46)
    int maxDrillthroughRecords();

    @VTID(47)
    void maxDrillthroughRecords(
        int rhs);

    @VTID(48)
    boolean isConnected();

    @VTID(49)
    mol.excel.XlCredentialsMethod serverCredentialsMethod();

    @VTID(50)
    void serverCredentialsMethod(
        mol.excel.XlCredentialsMethod rhs);

    @VTID(51)
    java.lang.String serverSSOApplicationID();

    @VTID(52)
    void serverSSOApplicationID(
        java.lang.String rhs);

    @VTID(53)
    boolean alwaysUseConnectionFile();

    @VTID(54)
    void alwaysUseConnectionFile(
        boolean rhs);

    @VTID(55)
    boolean serverFillColor();

    @VTID(56)
    void serverFillColor(
        boolean rhs);

    @VTID(57)
    boolean serverFontStyle();

    @VTID(58)
    void serverFontStyle(
        boolean rhs);

    @VTID(59)
    boolean serverNumberFormat();

    @VTID(60)
    void serverNumberFormat(
        boolean rhs);

    @VTID(61)
    boolean serverTextColor();

    @VTID(62)
    void serverTextColor(
        boolean rhs);

    @VTID(63)
    boolean retrieveInOfficeUILang();

    @VTID(64)
    void retrieveInOfficeUILang(
        boolean rhs);

}
