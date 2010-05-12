package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface UserAccess extends Com4jObject {
    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(2020)
    @PropGet
    boolean allowEdit();

    @DISPID(2020)
    @PropPut
    void allowEdit(
        boolean rhs);

    @DISPID(117)
    void delete();

}
