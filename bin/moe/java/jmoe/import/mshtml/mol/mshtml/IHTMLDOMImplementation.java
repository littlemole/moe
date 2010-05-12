package mol.mshtml  ;

import com4j.*;

@IID("{3050F80D-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLDOMImplementation extends Com4jObject {
    @VTID(7)
    boolean hasFeature(
        java.lang.String bstrfeature,
        @MarshalAs(NativeType.VARIANT) java.lang.Object version);

}
