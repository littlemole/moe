package mol.word  ;

import com4j.*;

@IID("{000209E7-0000-0000-C000-000000000046}")
public interface HTMLDivision extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.Range range();

    @VTID(11)
    mol.word.Borders borders();

    @VTID(11)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(12)
    float leftIndent();

    @VTID(13)
    void leftIndent(
        float prop);

    @VTID(14)
    float rightIndent();

    @VTID(15)
    void rightIndent(
        float prop);

    @VTID(16)
    float spaceBefore();

    @VTID(17)
    void spaceBefore(
        float prop);

    @VTID(18)
    float spaceAfter();

    @VTID(19)
    void spaceAfter(
        float prop);

    @VTID(20)
    mol.word.HTMLDivisions htmlDivisions();

    @VTID(20)
    @ReturnValue(defaultPropertyThrough={mol.word.HTMLDivisions.class})
    mol.word.HTMLDivision htmlDivisions(
        int index);

    @VTID(21)
    mol.word.HTMLDivision htmlDivisionParent(
        java.lang.Object levelsUp);

    @VTID(22)
    void delete();

}
