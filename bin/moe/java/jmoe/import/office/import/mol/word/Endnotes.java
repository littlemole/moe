package mol.word  ;

import com4j.*;

@IID("{00020941-0000-0000-C000-000000000046}")
public interface Endnotes extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word._Application application();

    @VTID(10)
    int creator();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    mol.word.WdEndnoteLocation location();

    @VTID(13)
    void location(
        mol.word.WdEndnoteLocation prop);

    @VTID(14)
    mol.word.WdNoteNumberStyle numberStyle();

    @VTID(15)
    void numberStyle(
        mol.word.WdNoteNumberStyle prop);

    @VTID(16)
    int startingNumber();

    @VTID(17)
    void startingNumber(
        int prop);

    @VTID(18)
    mol.word.WdNumberingRule numberingRule();

    @VTID(19)
    void numberingRule(
        mol.word.WdNumberingRule prop);

    @VTID(20)
    mol.word.Range separator();

    @VTID(21)
    mol.word.Range continuationSeparator();

    @VTID(22)
    mol.word.Range continuationNotice();

    @VTID(23)
    @DefaultMethod
    mol.word.Endnote item(
        int index);

    @VTID(24)
    mol.word.Endnote add(
        mol.word.Range range,
        java.lang.Object reference,
        java.lang.Object text);

    @VTID(25)
    void convert();

    @VTID(26)
    void swapWithFootnotes();

    @VTID(27)
    void resetSeparator();

    @VTID(28)
    void resetContinuationSeparator();

    @VTID(29)
    void resetContinuationNotice();

}
