package mol.word  ;

import com4j.*;

@IID("{ADD4EDF3-2F33-4734-9CE6-D476097C5ADA}")
public interface Rectangle extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdRectangleType rectangleType();

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
    mol.word.Lines lines();

    @VTID(16)
    @ReturnValue(defaultPropertyThrough={mol.word.Lines.class})
    mol.word.Line lines(
        int index);

}
