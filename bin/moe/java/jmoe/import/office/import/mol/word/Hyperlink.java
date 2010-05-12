package mol.word  ;

import com4j.*;

@IID("{0002099D-0000-0000-C000-000000000046}")
public interface Hyperlink extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    java.lang.String addressOld();

    @VTID(12)
    mol.office.MsoHyperlinkType type();

    @VTID(13)
    mol.word.Range range();

    @VTID(14)
    mol.word.Shape shape();

    @VTID(15)
    java.lang.String subAddressOld();

    @VTID(16)
    boolean extraInfoRequired();

    @VTID(17)
    void delete();

    @VTID(18)
    void follow(
        java.lang.Object newWindow,
        java.lang.Object addHistory,
        java.lang.Object extraInfo,
        java.lang.Object method,
        java.lang.Object headerInfo);

    @VTID(19)
    void addToFavorites();

    @VTID(20)
    void createNewDocument(
        java.lang.String fileName,
        boolean editNow,
        boolean overwrite);

    @VTID(21)
    java.lang.String address();

    @VTID(22)
    void address(
        java.lang.String prop);

    @VTID(23)
    java.lang.String subAddress();

    @VTID(24)
    void subAddress(
        java.lang.String prop);

    @VTID(25)
    java.lang.String emailSubject();

    @VTID(26)
    void emailSubject(
        java.lang.String prop);

    @VTID(27)
    java.lang.String screenTip();

    @VTID(28)
    void screenTip(
        java.lang.String prop);

    @VTID(29)
    java.lang.String textToDisplay();

    @VTID(30)
    void textToDisplay(
        java.lang.String prop);

    @VTID(31)
    java.lang.String target();

    @VTID(32)
    void target(
        java.lang.String prop);

}
