package mol.mshtml  ;

import com4j.*;

@IID("{3050F4B7-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLGenericElement extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject recordset();

    @VTID(8)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject namedRecordset(
        java.lang.String dataMember,
        java.lang.Object hierarchy);

}
