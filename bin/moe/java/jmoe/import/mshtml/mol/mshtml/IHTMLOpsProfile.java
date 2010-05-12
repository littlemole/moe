package mol.mshtml  ;

import com4j.*;

@IID("{3050F401-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLOpsProfile extends Com4jObject {
    @VTID(7)
    boolean addRequest(
        java.lang.String name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object reserved);

    @VTID(8)
    void clearRequest();

    @VTID(9)
    void doRequest(
        @MarshalAs(NativeType.VARIANT) java.lang.Object usage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fname,
        @MarshalAs(NativeType.VARIANT) java.lang.Object domain,
        @MarshalAs(NativeType.VARIANT) java.lang.Object path,
        @MarshalAs(NativeType.VARIANT) java.lang.Object expire,
        @MarshalAs(NativeType.VARIANT) java.lang.Object reserved);

    @VTID(10)
    java.lang.String getAttribute(
        java.lang.String name);

    @VTID(11)
    boolean setAttribute(
        java.lang.String name,
        java.lang.String value,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prefs);

    @VTID(12)
    boolean commitChanges();

    @VTID(13)
    boolean addReadRequest(
        java.lang.String name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object reserved);

    @VTID(14)
    void doReadRequest(
        @MarshalAs(NativeType.VARIANT) java.lang.Object usage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fname,
        @MarshalAs(NativeType.VARIANT) java.lang.Object domain,
        @MarshalAs(NativeType.VARIANT) java.lang.Object path,
        @MarshalAs(NativeType.VARIANT) java.lang.Object expire,
        @MarshalAs(NativeType.VARIANT) java.lang.Object reserved);

    @VTID(15)
    boolean doWriteRequest();

}
