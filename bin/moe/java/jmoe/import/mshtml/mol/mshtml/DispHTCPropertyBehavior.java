package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTCPropertyBehavior extends Com4jObject {
    @DISPID(-2147417612)
    void fireChange();

    @DISPID(-2147412971)
    @PropPut
    void value(
        java.lang.Object rhs);

    @DISPID(-2147412971)
    @PropGet
    java.lang.Object value();

}
