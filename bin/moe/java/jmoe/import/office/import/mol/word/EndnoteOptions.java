package mol.word  ;

import com4j.*;

@IID("{BF043168-F4DE-4E7C-B206-741A8B3EF71A}")
public interface EndnoteOptions extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdEndnoteLocation location();

    @VTID(11)
    void location(
        mol.word.WdEndnoteLocation prop);

    @VTID(12)
    mol.word.WdNoteNumberStyle numberStyle();

    @VTID(13)
    void numberStyle(
        mol.word.WdNoteNumberStyle prop);

    @VTID(14)
    int startingNumber();

    @VTID(15)
    void startingNumber(
        int prop);

    @VTID(16)
    mol.word.WdNumberingRule numberingRule();

    @VTID(17)
    void numberingRule(
        mol.word.WdNumberingRule prop);

}
