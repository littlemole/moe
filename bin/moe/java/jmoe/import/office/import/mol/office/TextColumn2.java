package mol.office  ;

import com4j.*;

@IID("{000C03B2-0000-0000-C000-000000000046}")
public interface TextColumn2 extends mol.office._IMsoDispObj {
    @VTID(9)
    int number();

    @VTID(10)
    void number(
        int number);

    @VTID(11)
    float spacing();

    @VTID(12)
    void spacing(
        float spacing);

    @VTID(13)
    mol.office.MsoTextDirection textDirection();

    @VTID(14)
    void textDirection(
        mol.office.MsoTextDirection direction);

}
