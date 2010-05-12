package mol.mshtml  ;

import com4j.*;

@IID("{3050F4B0-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLDOMAttribute extends Com4jObject {
    @VTID(7)
    java.lang.String nodeName();

    @VTID(8)
    void nodeValue(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(9)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object nodeValue();

    @VTID(10)
    boolean specified();

}
