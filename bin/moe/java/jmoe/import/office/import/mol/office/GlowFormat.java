package mol.office  ;

import com4j.*;

@IID("{000C03BD-0000-0000-C000-000000000046}")
public interface GlowFormat extends mol.office._IMsoDispObj {
    @VTID(9)
    float radius();

    @VTID(10)
    void radius(
        float radius);

    @VTID(11)
    mol.office.ColorFormat color();

}
