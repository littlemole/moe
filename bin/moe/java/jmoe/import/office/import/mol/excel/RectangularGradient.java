package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface RectangularGradient extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(2761)
    @PropGet
    mol.excel.ColorStops colorStops();

    @DISPID(2762)
    @PropGet
    double rectangleTop();

    @DISPID(2762)
    @PropPut
    void rectangleTop(
        double rhs);

    @DISPID(2763)
    @PropGet
    double rectangleBottom();

    @DISPID(2763)
    @PropPut
    void rectangleBottom(
        double rhs);

    @DISPID(2764)
    @PropGet
    double rectangleLeft();

    @DISPID(2764)
    @PropPut
    void rectangleLeft(
        double rhs);

    @DISPID(2765)
    @PropGet
    double rectangleRight();

    @DISPID(2765)
    @PropPut
    void rectangleRight(
        double rhs);

}
