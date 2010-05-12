package mol.mshtml  ;

import com4j.*;

@IID("{3050F5F4-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTCAttachBehavior extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    void fireEvent(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject evt);

    @VTID(8)
    void detachEvent();

}
