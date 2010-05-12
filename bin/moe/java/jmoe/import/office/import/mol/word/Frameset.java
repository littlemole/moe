package mol.word  ;

import com4j.*;

@IID("{000209E2-0000-0000-C000-000000000046}")
public interface Frameset extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.Frameset parentFrameset();

    @VTID(12)
    @DefaultMethod
    mol.word.WdFramesetType type();

    @VTID(13)
    mol.word.WdFramesetSizeType widthType();

    @VTID(14)
    void widthType(
        mol.word.WdFramesetSizeType prop);

    @VTID(15)
    mol.word.WdFramesetSizeType heightType();

    @VTID(16)
    void heightType(
        mol.word.WdFramesetSizeType prop);

    @VTID(17)
    int width();

    @VTID(18)
    void width(
        int prop);

    @VTID(19)
    int height();

    @VTID(20)
    void height(
        int prop);

    @VTID(21)
    int childFramesetCount();

    @VTID(22)
    mol.word.Frameset childFramesetItem(
        int index);

    @VTID(23)
    float framesetBorderWidth();

    @VTID(24)
    void framesetBorderWidth(
        float prop);

    @VTID(25)
    mol.word.WdColor framesetBorderColor();

    @VTID(26)
    void framesetBorderColor(
        mol.word.WdColor prop);

    @VTID(27)
    mol.word.WdScrollbarType frameScrollbarType();

    @VTID(28)
    void frameScrollbarType(
        mol.word.WdScrollbarType prop);

    @VTID(29)
    boolean frameResizable();

    @VTID(30)
    void frameResizable(
        boolean prop);

    @VTID(31)
    java.lang.String frameName();

    @VTID(32)
    void frameName(
        java.lang.String prop);

    @VTID(33)
    boolean frameDisplayBorders();

    @VTID(34)
    void frameDisplayBorders(
        boolean prop);

    @VTID(35)
    java.lang.String frameDefaultURL();

    @VTID(36)
    void frameDefaultURL(
        java.lang.String prop);

    @VTID(37)
    boolean frameLinkToFile();

    @VTID(38)
    void frameLinkToFile(
        boolean prop);

    @VTID(39)
    mol.word.Frameset addNewFrame(
        mol.word.WdFramesetNewFrameLocation where);

    @VTID(40)
    void delete();

}
