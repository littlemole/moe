package mol.mshtml  ;

import com4j.*;

@IID("{3050F4FD-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTCDefaultDispatch extends Com4jObject {
    @VTID(7)
    mol.mshtml.IHTMLElement element();

    @VTID(8)
    mol.mshtml.IHTMLEventObj createEventObject();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject defaults();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject document();

}
