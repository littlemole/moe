package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Hyperlink extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(197)
    @PropGet
    mol.excel.Range range();

    @DISPID(1582)
    @PropGet
    mol.excel.Shape shape();

    @DISPID(1471)
    @PropGet
    java.lang.String subAddress();

    @DISPID(1471)
    @PropPut
    void subAddress(
        java.lang.String rhs);

    @DISPID(236)
    @PropGet
    java.lang.String address();

    @DISPID(236)
    @PropPut
    void address(
        java.lang.String rhs);

    @DISPID(108)
    @PropGet
    int type();

    @DISPID(1476)
    void addToFavorites();

    @DISPID(117)
    void delete();

    @DISPID(1616)
    void follow(
        java.lang.Object newWindow,
        java.lang.Object addHistory,
        java.lang.Object extraInfo,
        java.lang.Object method,
        java.lang.Object headerInfo);

    @DISPID(1883)
    @PropGet
    java.lang.String emailSubject();

    @DISPID(1883)
    @PropPut
    void emailSubject(
        java.lang.String rhs);

    @DISPID(1881)
    @PropGet
    java.lang.String screenTip();

    @DISPID(1881)
    @PropPut
    void screenTip(
        java.lang.String rhs);

    @DISPID(1882)
    @PropGet
    java.lang.String textToDisplay();

    @DISPID(1882)
    @PropPut
    void textToDisplay(
        java.lang.String rhs);

    @DISPID(1884)
    void createNewDocument(
        java.lang.String filename,
        boolean editNow,
        boolean overwrite);

}
