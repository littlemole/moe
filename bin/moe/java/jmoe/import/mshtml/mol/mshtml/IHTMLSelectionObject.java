package mol.mshtml  ;

import com4j.*;

@IID("{3050F25A-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLSelectionObject extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject createRange();

    @VTID(8)
    void empty();

    @VTID(9)
    void clear();

    @VTID(10)
    java.lang.String type();

}
