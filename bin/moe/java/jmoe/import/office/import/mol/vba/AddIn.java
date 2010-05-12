package mol.vba  ;

import com4j.*;

@IID("{DA936B64-AC8B-11D1-B6E5-00A0C90F2744}")
public interface AddIn extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String description();

    @VTID(8)
    @DefaultMethod
    void description(
        java.lang.String lpbstr);

    @VTID(9)
    mol.vba.VBE vbe();

    @VTID(10)
    mol.vba._AddIns collection();

    @VTID(11)
    java.lang.String progId();

    @VTID(12)
    java.lang.String guid();

    @VTID(13)
    boolean connect();

    @VTID(14)
    void connect(
        boolean lpfConnect);

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject object();

    @VTID(16)
    void object(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject lppdisp);

}
