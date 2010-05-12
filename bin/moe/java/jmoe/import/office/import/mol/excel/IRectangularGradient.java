package mol.excel  ;

import com4j.*;

@IID("{000244B0-0001-0000-C000-000000000046}")
public interface IRectangularGradient extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.ColorStops colorStops();

    @VTID(11)
    double rectangleTop();

    @VTID(12)
    void rectangleTop(
        double rhs);

    @VTID(13)
    double rectangleBottom();

    @VTID(14)
    void rectangleBottom(
        double rhs);

    @VTID(15)
    double rectangleLeft();

    @VTID(16)
    void rectangleLeft(
        double rhs);

    @VTID(17)
    double rectangleRight();

    @VTID(18)
    void rectangleRight(
        double rhs);

}
