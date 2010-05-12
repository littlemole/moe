package mol.office  ;

import com4j.*;

@IID("{000C0368-0000-0000-C000-000000000046}")
public interface ScopeFolder extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String name();

    @VTID(10)
    java.lang.String path();

    @VTID(11)
    mol.office.ScopeFolders scopeFolders();

    @VTID(11)
    @ReturnValue(defaultPropertyThrough={mol.office.ScopeFolders.class})
    mol.office.ScopeFolder scopeFolders(
        int index);

    @VTID(12)
    void addToSearchFolders();

}
