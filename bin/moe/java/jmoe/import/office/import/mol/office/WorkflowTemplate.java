package mol.office  ;

import com4j.*;

@IID("{000CD902-0000-0000-C000-000000000046}")
public interface WorkflowTemplate extends mol.office._IMsoDispObj {
    @VTID(9)
    java.lang.String id();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    java.lang.String description();

    @VTID(12)
    java.lang.String documentLibraryName();

    @VTID(13)
    java.lang.String documentLibraryURL();

    @VTID(14)
    int show();

}
