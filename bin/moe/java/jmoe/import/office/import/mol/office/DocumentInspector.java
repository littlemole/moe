package mol.office  ;

import com4j.*;

@IID("{000C0393-0000-0000-C000-000000000046}")
public interface DocumentInspector extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String name();

    @VTID(10)
    java.lang.String description();

    @VTID(11)
    void inspect(
        Holder<mol.office.MsoDocInspectorStatus> status,
        Holder<java.lang.String> results);

    @VTID(12)
    void fix(
        Holder<mol.office.MsoDocInspectorStatus> status,
        Holder<java.lang.String> results);

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
