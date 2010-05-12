package mol.word  ;

import com4j.*;

@IID("{0002094B-0000-0000-C000-000000000046}")
public interface Columns extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word._Application application();

    @VTID(10)
    int creator();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    mol.word.Column first();

    @VTID(13)
    mol.word.Column last();

    @VTID(14)
    float width();

    @VTID(15)
    void width(
        float prop);

    @VTID(16)
    mol.word.Borders borders();

    @VTID(16)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(17)
    void borders(
        mol.word.Borders prop);

    @VTID(18)
    mol.word.Shading shading();

    @VTID(19)
    @DefaultMethod
    mol.word.Column item(
        int index);

    @VTID(20)
    mol.word.Column add(
        java.lang.Object beforeColumn);

    @VTID(21)
    void select();

    @VTID(22)
    void delete();

    @VTID(23)
    void setWidth(
        float columnWidth,
        mol.word.WdRulerStyle rulerStyle);

    @VTID(24)
    void autoFit();

    @VTID(25)
    void distributeWidth();

    @VTID(26)
    int nestingLevel();

    @VTID(27)
    float preferredWidth();

    @VTID(28)
    void preferredWidth(
        float prop);

    @VTID(29)
    mol.word.WdPreferredWidthType preferredWidthType();

    @VTID(30)
    void preferredWidthType(
        mol.word.WdPreferredWidthType prop);

}
