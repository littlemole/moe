package mol.office  ;

import com4j.*;

@IID("{000C0358-0000-0000-C000-000000000046}")
public interface HTMLProjectItem extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String name();

    @VTID(10)
    boolean isOpen();

    @VTID(11)
    void loadFromFile(
        java.lang.String fileName);

    @VTID(12)
    void open(
        mol.office.MsoHTMLProjectOpen openKind);

    @VTID(13)
    void saveCopyAs(
        java.lang.String fileName);

    @VTID(14)
    java.lang.String text();

    @VTID(15)
    void text(
        java.lang.String text);

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
