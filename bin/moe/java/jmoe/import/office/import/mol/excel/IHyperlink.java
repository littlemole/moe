package mol.excel  ;

import com4j.*;

@IID("{00024431-0001-0000-C000-000000000046}")
public interface IHyperlink extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    mol.excel.Range range();

    @VTID(12)
    mol.excel.Shape shape();

    @VTID(13)
    java.lang.String subAddress();

    @VTID(14)
    void subAddress(
        java.lang.String rhs);

    @VTID(15)
    java.lang.String address();

    @VTID(16)
    void address(
        java.lang.String rhs);

    @VTID(17)
    int type();

    @VTID(18)
    void addToFavorites();

    @VTID(19)
    void delete();

    @VTID(20)
    void follow(
        @MarshalAs(NativeType.VARIANT) java.lang.Object newWindow,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addHistory,
        @MarshalAs(NativeType.VARIANT) java.lang.Object extraInfo,
        @MarshalAs(NativeType.VARIANT) java.lang.Object method,
        @MarshalAs(NativeType.VARIANT) java.lang.Object headerInfo);

    @VTID(21)
    java.lang.String emailSubject();

    @VTID(22)
    void emailSubject(
        java.lang.String rhs);

    @VTID(23)
    java.lang.String screenTip();

    @VTID(24)
    void screenTip(
        java.lang.String rhs);

    @VTID(25)
    java.lang.String textToDisplay();

    @VTID(26)
    void textToDisplay(
        java.lang.String rhs);

    @VTID(27)
    void createNewDocument(
        java.lang.String filename,
        boolean editNow,
        boolean overwrite);

}
