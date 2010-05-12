package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Mailer extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(983)
    @PropGet
    java.lang.Object bccRecipients();

    @DISPID(983)
    @PropPut
    void bccRecipients(
        java.lang.Object rhs);

    @DISPID(982)
    @PropGet
    java.lang.Object ccRecipients();

    @DISPID(982)
    @PropPut
    void ccRecipients(
        java.lang.Object rhs);

    @DISPID(984)
    @PropGet
    java.lang.Object enclosures();

    @DISPID(984)
    @PropPut
    void enclosures(
        java.lang.Object rhs);

    @DISPID(986)
    @PropGet
    boolean received();

    @DISPID(987)
    @PropGet
    java.util.Date sendDateTime();

    @DISPID(988)
    @PropGet
    java.lang.String sender();

    @DISPID(953)
    @PropGet
    java.lang.String subject();

    @DISPID(953)
    @PropPut
    void subject(
        java.lang.String rhs);

    @DISPID(981)
    @PropGet
    java.lang.Object toRecipients();

    @DISPID(981)
    @PropPut
    void toRecipients(
        java.lang.Object rhs);

    @DISPID(974)
    @PropGet
    java.lang.Object whichAddress();

    @DISPID(974)
    @PropPut
    void whichAddress(
        java.lang.Object rhs);

}
