package mol.mshtml  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface DispHTMLElementCollection extends Com4jObject {
    @DISPID(1501)
    java.lang.String toString_();

    @DISPID(1500)
    @PropPut
    void length(
        int rhs);

    @DISPID(1500)
    @PropGet
    int length();

    @DISPID(-4)
    @PropGet
    com4j.Com4jObject _newEnum();

    @DISPID(0)
    @DefaultMethod
    com4j.Com4jObject item(
        java.lang.Object name,
        java.lang.Object index);

    @DISPID(1502)
    com4j.Com4jObject tags(
        java.lang.Object tagName);

    @DISPID(1505)
    com4j.Com4jObject urns(
        java.lang.Object urn);

    @DISPID(1506)
    com4j.Com4jObject namedItem(
        java.lang.String name);

}
