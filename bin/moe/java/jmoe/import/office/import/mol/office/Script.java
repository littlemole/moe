package mol.office  ;

import com4j.*;

@IID("{000C0341-0000-0000-C000-000000000046}")
public interface Script extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String extended();

    @VTID(11)
    void extended(
        java.lang.String extended);

    @VTID(12)
    java.lang.String id();

    @VTID(13)
    void id(
        java.lang.String id);

    @VTID(14)
    mol.office.MsoScriptLanguage language();

    @VTID(15)
    void language(
        mol.office.MsoScriptLanguage language);

    @VTID(16)
    mol.office.MsoScriptLocation location();

    @VTID(17)
    void delete();

    @VTID(18)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject shape();

    @VTID(19)
    @DefaultMethod
    java.lang.String scriptText();

    @VTID(20)
    @DefaultMethod
    void scriptText(
        java.lang.String script);

}
