package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface AddIn extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(574)
    @PropGet
    java.lang.String author();

    @DISPID(575)
    @PropGet
    java.lang.String comments();

    @DISPID(289)
    @PropGet
    java.lang.String fullName();

    @DISPID(550)
    @PropGet
    boolean installed();

    @DISPID(550)
    @PropPut
    void installed(
        boolean rhs);

    @DISPID(577)
    @PropGet
    java.lang.String keywords();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(291)
    @PropGet
    java.lang.String path();

    @DISPID(953)
    @PropGet
    java.lang.String subject();

    @DISPID(199)
    @PropGet
    java.lang.String title();

    @DISPID(1523)
    @PropGet
    java.lang.String progID();

    @DISPID(2043)
    @PropGet
    java.lang.String clsid();

}
