package mol.office  ;

import com4j.*;

@IID("{000CD706-0000-0000-C000-000000000046}")
public interface IDocumentInspector extends Com4jObject {
    @VTID(3)
    void getInfo(
        Holder<java.lang.String> name,
        Holder<java.lang.String> desc);

    @VTID(4)
    void inspect(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject doc,
        Holder<mol.office.MsoDocInspectorStatus> status,
        Holder<java.lang.String> result,
        Holder<java.lang.String> action);

    @VTID(5)
    void fix(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject doc,
        int hwnd,
        Holder<mol.office.MsoDocInspectorStatus> status,
        Holder<java.lang.String> result);

}
