package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface OLEFormat extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(304)
    void activate();

    @DISPID(1049)
    @PropGet
    com4j.Com4jObject object();

    @DISPID(1523)
    @PropGet
    java.lang.String progID();

    @DISPID(606)
    void verb(
        java.lang.Object verb);

}
