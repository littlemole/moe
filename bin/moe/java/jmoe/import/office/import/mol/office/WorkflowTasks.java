package mol.office  ;

import com4j.*;

@IID("{000CD901-0000-0000-C000-000000000046}")
public interface WorkflowTasks extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.WorkflowTask item(
        int index);

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

}
