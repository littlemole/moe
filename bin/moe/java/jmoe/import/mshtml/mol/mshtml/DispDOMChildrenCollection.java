package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispDOMChildrenCollection extends Com4jObject {
    @DISPID(1500)
    @PropGet
    int length();

    @DISPID(-4)
    @PropGet
    com4j.Com4jObject _newEnum();

    @DISPID(0)
    @DefaultMethod
    com4j.Com4jObject item(
        int index);

}
