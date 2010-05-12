package mol.word  ;

import com4j.*;

@IID("{0002093B-0000-0000-C000-000000000046}")
public interface Border extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    boolean visible();

    @VTID(11)
    @DefaultMethod
    void visible(
        boolean prop);

    @VTID(12)
    mol.word.WdColorIndex colorIndex();

    @VTID(13)
    void colorIndex(
        mol.word.WdColorIndex prop);

    @VTID(14)
    boolean inside();

    @VTID(15)
    mol.word.WdLineStyle lineStyle();

    @VTID(16)
    void lineStyle(
        mol.word.WdLineStyle prop);

    @VTID(17)
    mol.word.WdLineWidth lineWidth();

    @VTID(18)
    void lineWidth(
        mol.word.WdLineWidth prop);

    @VTID(19)
    mol.word.WdPageBorderArt artStyle();

    @VTID(20)
    void artStyle(
        mol.word.WdPageBorderArt prop);

    @VTID(21)
    int artWidth();

    @VTID(22)
    void artWidth(
        int prop);

    @VTID(23)
    mol.word.WdColor color();

    @VTID(24)
    void color(
        mol.word.WdColor prop);

}
