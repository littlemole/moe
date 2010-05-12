package mol.office  ;

import com4j.*;

@IID("{000C0367-0000-0000-C000-000000000046}")
public interface SearchScope extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    mol.office.MsoSearchIn type();

    @VTID(10)
    mol.office.ScopeFolder scopeFolder();

}
