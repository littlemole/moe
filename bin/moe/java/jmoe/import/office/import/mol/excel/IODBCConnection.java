package mol.excel  ;

import com4j.*;

@IID("{0002448E-0001-0000-C000-000000000046}")
public interface IODBCConnection extends Com4jObject {
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
    void cancelRefresh();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object commandText();

    @VTID(14)
    void commandText(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(15)
    mol.excel.XlCmdType commandType();

    @VTID(16)
    void commandType(
        mol.excel.XlCmdType rhs);

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object connection();

    @VTID(18)
    void connection(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(19)
    boolean enableRefresh();

    @VTID(20)
    void enableRefresh(
        boolean rhs);

    @VTID(21)
    void refresh();

    @VTID(22)
    java.util.Date refreshDate();

    @VTID(23)
    boolean refreshing();

    @VTID(24)
    boolean refreshOnFileOpen();

    @VTID(25)
    void refreshOnFileOpen(
        boolean rhs);

    @VTID(26)
    int refreshPeriod();

    @VTID(27)
    void refreshPeriod(
        int rhs);

    @VTID(28)
    mol.excel.XlRobustConnect robustConnect();

    @VTID(29)
    void robustConnect(
        mol.excel.XlRobustConnect rhs);

    @VTID(30)
    void saveAsODC(
        java.lang.String odcFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object description,
        @MarshalAs(NativeType.VARIANT) java.lang.Object keywords);

    @VTID(31)
    boolean savePassword();

    @VTID(32)
    void savePassword(
        boolean rhs);

    @VTID(33)
    java.lang.String sourceConnectionFile();

    @VTID(34)
    void sourceConnectionFile(
        java.lang.String rhs);

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object sourceData();

    @VTID(36)
    void sourceData(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(37)
    java.lang.String sourceDataFile();

    @VTID(38)
    void sourceDataFile(
        java.lang.String rhs);

    @VTID(39)
    mol.excel.XlCredentialsMethod serverCredentialsMethod();

    @VTID(40)
    void serverCredentialsMethod(
        mol.excel.XlCredentialsMethod rhs);

    @VTID(41)
    java.lang.String serverSSOApplicationID();

    @VTID(42)
    void serverSSOApplicationID(
        java.lang.String rhs);

    @VTID(43)
    boolean alwaysUseConnectionFile();

    @VTID(44)
    void alwaysUseConnectionFile(
        boolean rhs);

}
