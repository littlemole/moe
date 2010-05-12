package mol.mshtml  ;

import com4j.*;

@IID("{3050F3EE-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLFiltersCollection extends Com4jObject {
    @VTID(7)
    int length();

    @VTID(8)
    com4j.Com4jObject _newEnum();

    @VTID(9)
    @DefaultMethod
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object item(
        java.lang.Object pvarIndex);

}
