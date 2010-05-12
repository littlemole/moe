package mol.mshtml  ;

import com4j.*;

@IID("{3050F6B8-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLNamespaceCollection extends Com4jObject {
    @VTID(7)
    int length();

    @VTID(8)
    @DefaultMethod
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject add(
        java.lang.String bstrNamespace,
        java.lang.String bstrUrn,
        @MarshalAs(NativeType.VARIANT) java.lang.Object implementationUrl);

}
