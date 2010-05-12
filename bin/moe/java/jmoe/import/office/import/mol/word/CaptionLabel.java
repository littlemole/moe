package mol.word  ;

import com4j.*;

@IID("{00020979-0000-0000-C000-000000000046}")
public interface CaptionLabel extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String name();

    @VTID(11)
    boolean builtIn();

    @VTID(12)
    mol.word.WdCaptionLabelID id();

    @VTID(13)
    boolean includeChapterNumber();

    @VTID(14)
    void includeChapterNumber(
        boolean prop);

    @VTID(15)
    mol.word.WdCaptionNumberStyle numberStyle();

    @VTID(16)
    void numberStyle(
        mol.word.WdCaptionNumberStyle prop);

    @VTID(17)
    int chapterStyleLevel();

    @VTID(18)
    void chapterStyleLevel(
        int prop);

    @VTID(19)
    mol.word.WdSeparatorType separator();

    @VTID(20)
    void separator(
        mol.word.WdSeparatorType prop);

    @VTID(21)
    mol.word.WdCaptionPosition position();

    @VTID(22)
    void position(
        mol.word.WdCaptionPosition prop);

    @VTID(23)
    void delete();

}
