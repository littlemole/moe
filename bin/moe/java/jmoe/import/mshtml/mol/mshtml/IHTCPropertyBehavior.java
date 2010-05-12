package mol.mshtml  ;

import com4j.*;

@IID("{3050F5DF-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTCPropertyBehavior extends Com4jObject {
    @VTID(7)
    void fireChange();

    @VTID(8)
    void value(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(9)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value();

}
