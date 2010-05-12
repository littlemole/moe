package mol.word  ;

import com4j.*;

@IID("{000209DE-0000-0000-C000-000000000046}")
public interface HorizontalLineFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    float percentWidth();

    @VTID(11)
    void percentWidth(
        float prop);

    @VTID(12)
    boolean noShade();

    @VTID(13)
    void noShade(
        boolean prop);

    @VTID(14)
    mol.word.WdHorizontalLineAlignment alignment();

    @VTID(15)
    void alignment(
        mol.word.WdHorizontalLineAlignment prop);

    @VTID(16)
    mol.word.WdHorizontalLineWidthType widthType();

    @VTID(17)
    void widthType(
        mol.word.WdHorizontalLineWidthType prop);

}
