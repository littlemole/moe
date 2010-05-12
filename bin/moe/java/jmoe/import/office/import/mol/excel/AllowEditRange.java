package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface AllowEditRange extends Com4jObject {
    @DISPID(199)
    @PropGet
    java.lang.String title();

    @DISPID(199)
    @PropPut
    void title(
        java.lang.String rhs);

    @DISPID(197)
    @PropGet
    mol.excel.Range range();

    @DISPID(197)
    @PropPut
    void range(
        mol.excel.Range rhs);

    @DISPID(2237)
    void changePassword(
        java.lang.String password);

    @DISPID(117)
    void delete();

    @DISPID(285)
    void unprotect(
        java.lang.Object password);

    @DISPID(2238)
    @PropGet
    mol.excel.UserAccessList users();

}
