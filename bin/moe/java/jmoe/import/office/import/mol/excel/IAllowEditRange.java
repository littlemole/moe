package mol.excel  ;

import com4j.*;

@IID("{0002446B-0001-0000-C000-000000000046}")
public interface IAllowEditRange extends Com4jObject {
    @VTID(7)
    java.lang.String title();

    @VTID(8)
    void title(
        java.lang.String rhs);

    @VTID(9)
    mol.excel.Range range();

    @VTID(10)
    void range(
        mol.excel.Range rhs);

    @VTID(11)
    void changePassword(
        java.lang.String password);

    @VTID(12)
    void delete();

    @VTID(13)
    void unprotect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password);

    @VTID(14)
    mol.excel.UserAccessList users();

}
