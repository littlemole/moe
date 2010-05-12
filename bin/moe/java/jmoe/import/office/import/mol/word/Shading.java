package mol.word  ;

import com4j.*;

@IID("{0002093A-0000-0000-C000-000000000046}")
public interface Shading extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdColorIndex foregroundPatternColorIndex();

    @VTID(11)
    void foregroundPatternColorIndex(
        mol.word.WdColorIndex prop);

    @VTID(12)
    mol.word.WdColorIndex backgroundPatternColorIndex();

    @VTID(13)
    void backgroundPatternColorIndex(
        mol.word.WdColorIndex prop);

    @VTID(14)
    mol.word.WdTextureIndex texture();

    @VTID(15)
    void texture(
        mol.word.WdTextureIndex prop);

    @VTID(16)
    mol.word.WdColor foregroundPatternColor();

    @VTID(17)
    void foregroundPatternColor(
        mol.word.WdColor prop);

    @VTID(18)
    mol.word.WdColor backgroundPatternColor();

    @VTID(19)
    void backgroundPatternColor(
        mol.word.WdColor prop);

}
