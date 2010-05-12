package mol.word  ;

import com4j.*;

@IID("{AE6CE2F5-B9D3-407D-85A8-0F10C63289A4}")
public interface Line extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdLineType lineType();

    @VTID(11)
    int left();

    @VTID(12)
    int top();

    @VTID(13)
    int width();

    @VTID(14)
    int height();

    @VTID(15)
    mol.word.Range range();

    @VTID(16)
    mol.word.Rectangles rectangles();

    @VTID(16)
    @ReturnValue(defaultPropertyThrough={mol.word.Rectangles.class})
    mol.word.Rectangle rectangles(
        int index);

}
