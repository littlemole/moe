package mol.office  ;

import com4j.*;

@IID("{000C038C-0000-0000-C000-000000000046}")
public interface MsoDebugOptions_UTRunResult extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    boolean passed();

    @VTID(10)
    java.lang.String errorString();

}
