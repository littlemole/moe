package mol.office  ;

import com4j.*;

@IID("{000CD900-0000-0000-C000-000000000046}")
public interface WorkflowTask extends mol.office._IMsoDispObj {
    @VTID(9)
    java.lang.String id();

    @VTID(10)
    java.lang.String listID();

    @VTID(11)
    java.lang.String workflowID();

    @VTID(12)
    java.lang.String name();

    @VTID(13)
    java.lang.String description();

    @VTID(14)
    java.lang.String assignedTo();

    @VTID(15)
    java.lang.String createdBy();

    @VTID(16)
    java.util.Date dueDate();

    @VTID(17)
    java.util.Date createdDate();

    @VTID(18)
    int show();

}
