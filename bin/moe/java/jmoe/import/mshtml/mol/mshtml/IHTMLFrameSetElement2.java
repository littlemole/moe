package mol.mshtml  ;

import com4j.*;

@IID("{3050F5C6-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLFrameSetElement2 extends Com4jObject {
    @VTID(7)
    void onbeforeprint(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onbeforeprint();

    @VTID(9)
    void onafterprint(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onafterprint();

}
