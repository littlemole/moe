package mol.word  ;

import com4j.*;

@IID("{352840A9-AF7D-4CA4-87FC-21C68FDAB3E4}")
public interface Page extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int left();

    @VTID(11)
    int top();

    @VTID(12)
    int width();

    @VTID(13)
    int height();

    @VTID(14)
    mol.word.Rectangles rectangles();

    @VTID(14)
    @ReturnValue(defaultPropertyThrough={mol.word.Rectangles.class})
    mol.word.Rectangle rectangles(
        int index);

    @VTID(15)
    mol.word.Breaks breaks();

    @VTID(15)
    @ReturnValue(defaultPropertyThrough={mol.word.Breaks.class})
    mol.word.Break breaks(
        int index);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object enhMetaFileBits();

}
