package mol.excel  ;

import com4j.*;

@IID("{0002446D-0001-0000-C000-000000000046}")
public interface IUserAccess extends Com4jObject {
    @VTID(7)
    java.lang.String name();

    @VTID(8)
    boolean allowEdit();

    @VTID(9)
    void allowEdit(
        boolean rhs);

    @VTID(10)
    void delete();

}
