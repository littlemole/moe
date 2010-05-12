package mol.office  ;

import com4j.*;

@IID("{000C0356-0000-0000-C000-000000000046}")
public interface HTMLProject extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    mol.office.MsoHTMLProjectState state();

    @VTID(10)
    void refreshProject(
        boolean refresh);

    @VTID(11)
    void refreshDocument(
        boolean refresh);

    @VTID(12)
    mol.office.HTMLProjectItems htmlProjectItems();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.office.HTMLProjectItems.class})
    mol.office.HTMLProjectItem htmlProjectItems(
        java.lang.Object index);

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(14)
    void open(
        mol.office.MsoHTMLProjectOpen openKind);

}
