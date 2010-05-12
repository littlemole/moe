package mol.word  ;

import com4j.*;

@IID("{00020949-0000-0000-C000-000000000046}")
public interface AutoCorrect extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean correctDays();

    @VTID(11)
    void correctDays(
        boolean prop);

    @VTID(12)
    boolean correctInitialCaps();

    @VTID(13)
    void correctInitialCaps(
        boolean prop);

    @VTID(14)
    boolean correctSentenceCaps();

    @VTID(15)
    void correctSentenceCaps(
        boolean prop);

    @VTID(16)
    boolean replaceText();

    @VTID(17)
    void replaceText(
        boolean prop);

    @VTID(18)
    mol.word.AutoCorrectEntries entries();

    @VTID(18)
    @ReturnValue(defaultPropertyThrough={mol.word.AutoCorrectEntries.class})
    mol.word.AutoCorrectEntry entries(
        java.lang.Object index);

    @VTID(19)
    mol.word.FirstLetterExceptions firstLetterExceptions();

    @VTID(19)
    @ReturnValue(defaultPropertyThrough={mol.word.FirstLetterExceptions.class})
    mol.word.FirstLetterException firstLetterExceptions(
        java.lang.Object index);

    @VTID(20)
    boolean firstLetterAutoAdd();

    @VTID(21)
    void firstLetterAutoAdd(
        boolean prop);

    @VTID(22)
    mol.word.TwoInitialCapsExceptions twoInitialCapsExceptions();

    @VTID(22)
    @ReturnValue(defaultPropertyThrough={mol.word.TwoInitialCapsExceptions.class})
    mol.word.TwoInitialCapsException twoInitialCapsExceptions(
        java.lang.Object index);

    @VTID(23)
    boolean twoInitialCapsAutoAdd();

    @VTID(24)
    void twoInitialCapsAutoAdd(
        boolean prop);

    @VTID(25)
    boolean correctCapsLock();

    @VTID(26)
    void correctCapsLock(
        boolean prop);

    @VTID(27)
    boolean correctHangulAndAlphabet();

    @VTID(28)
    void correctHangulAndAlphabet(
        boolean prop);

    @VTID(29)
    mol.word.HangulAndAlphabetExceptions hangulAndAlphabetExceptions();

    @VTID(29)
    @ReturnValue(defaultPropertyThrough={mol.word.HangulAndAlphabetExceptions.class})
    mol.word.HangulAndAlphabetException hangulAndAlphabetExceptions(
        java.lang.Object index);

    @VTID(30)
    boolean hangulAndAlphabetAutoAdd();

    @VTID(31)
    void hangulAndAlphabetAutoAdd(
        boolean prop);

    @VTID(32)
    boolean replaceTextFromSpellingChecker();

    @VTID(33)
    void replaceTextFromSpellingChecker(
        boolean prop);

    @VTID(34)
    boolean otherCorrectionsAutoAdd();

    @VTID(35)
    void otherCorrectionsAutoAdd(
        boolean prop);

    @VTID(36)
    mol.word.OtherCorrectionsExceptions otherCorrectionsExceptions();

    @VTID(36)
    @ReturnValue(defaultPropertyThrough={mol.word.OtherCorrectionsExceptions.class})
    mol.word.OtherCorrectionsException otherCorrectionsExceptions(
        java.lang.Object index);

    @VTID(37)
    boolean correctKeyboardSetting();

    @VTID(38)
    void correctKeyboardSetting(
        boolean prop);

    @VTID(39)
    boolean correctTableCells();

    @VTID(40)
    void correctTableCells(
        boolean prop);

    @VTID(41)
    boolean displayAutoCorrectOptions();

    @VTID(42)
    void displayAutoCorrectOptions(
        boolean prop);

}
