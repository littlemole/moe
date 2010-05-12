package mol.office  ;

import com4j.*;

@IID("{000C03BF-0000-0000-C000-000000000046}")
public interface GradientStop extends mol.office._IMsoDispObj {
    @VTID(9)
    mol.office.ColorFormat color();

    @VTID(10)
    float position();

    @VTID(11)
    void position(
        float position);

    @VTID(12)
    float transparency();

    @VTID(13)
    void transparency(
        float transparency);

}
