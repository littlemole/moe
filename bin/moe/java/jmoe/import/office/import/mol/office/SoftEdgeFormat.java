package mol.office  ;

import com4j.*;

@IID("{000C03BC-0000-0000-C000-000000000046}")
public interface SoftEdgeFormat extends mol.office._IMsoDispObj {
    @VTID(9)
    mol.office.MsoSoftEdgeType type();

    @VTID(10)
    void type(
        mol.office.MsoSoftEdgeType type);

}
