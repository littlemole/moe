package mol.word  ;

import com4j.*;

@IID("{0002093C-0000-0000-C000-000000000046}")
public interface Borders extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(11)
    int count();

    @VTID(12)
    int enable();

    @VTID(13)
    void enable(
        int prop);

    @VTID(14)
    int distanceFromTop();

    @VTID(15)
    void distanceFromTop(
        int prop);

    @VTID(16)
    boolean shadow();

    @VTID(17)
    void shadow(
        boolean prop);

    @VTID(18)
    mol.word.WdLineStyle insideLineStyle();

    @VTID(19)
    void insideLineStyle(
        mol.word.WdLineStyle prop);

    @VTID(20)
    mol.word.WdLineStyle outsideLineStyle();

    @VTID(21)
    void outsideLineStyle(
        mol.word.WdLineStyle prop);

    @VTID(22)
    mol.word.WdLineWidth insideLineWidth();

    @VTID(23)
    void insideLineWidth(
        mol.word.WdLineWidth prop);

    @VTID(24)
    mol.word.WdLineWidth outsideLineWidth();

    @VTID(25)
    void outsideLineWidth(
        mol.word.WdLineWidth prop);

    @VTID(26)
    mol.word.WdColorIndex insideColorIndex();

    @VTID(27)
    void insideColorIndex(
        mol.word.WdColorIndex prop);

    @VTID(28)
    mol.word.WdColorIndex outsideColorIndex();

    @VTID(29)
    void outsideColorIndex(
        mol.word.WdColorIndex prop);

    @VTID(30)
    int distanceFromLeft();

    @VTID(31)
    void distanceFromLeft(
        int prop);

    @VTID(32)
    int distanceFromBottom();

    @VTID(33)
    void distanceFromBottom(
        int prop);

    @VTID(34)
    int distanceFromRight();

    @VTID(35)
    void distanceFromRight(
        int prop);

    @VTID(36)
    boolean alwaysInFront();

    @VTID(37)
    void alwaysInFront(
        boolean prop);

    @VTID(38)
    boolean surroundHeader();

    @VTID(39)
    void surroundHeader(
        boolean prop);

    @VTID(40)
    boolean surroundFooter();

    @VTID(41)
    void surroundFooter(
        boolean prop);

    @VTID(42)
    boolean joinBorders();

    @VTID(43)
    void joinBorders(
        boolean prop);

    @VTID(44)
    boolean hasHorizontal();

    @VTID(45)
    boolean hasVertical();

    @VTID(46)
    mol.word.WdBorderDistanceFrom distanceFrom();

    @VTID(47)
    void distanceFrom(
        mol.word.WdBorderDistanceFrom prop);

    @VTID(48)
    boolean enableFirstPageInSection();

    @VTID(49)
    void enableFirstPageInSection(
        boolean prop);

    @VTID(50)
    boolean enableOtherPagesInSection();

    @VTID(51)
    void enableOtherPagesInSection(
        boolean prop);

    @VTID(52)
    @DefaultMethod
    mol.word.Border item(
        mol.word.WdBorderType index);

    @VTID(53)
    void applyPageBordersToAllSections();

    @VTID(54)
    mol.word.WdColor insideColor();

    @VTID(55)
    void insideColor(
        mol.word.WdColor prop);

    @VTID(56)
    mol.word.WdColor outsideColor();

    @VTID(57)
    void outsideColor(
        mol.word.WdColor prop);

}
