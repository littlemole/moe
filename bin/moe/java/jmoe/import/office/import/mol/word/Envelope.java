package mol.word  ;

import com4j.*;

@IID("{00020918-0000-0000-C000-000000000046}")
public interface Envelope extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.Range address();

    @VTID(11)
    mol.word.Range returnAddress();

    @VTID(12)
    boolean defaultPrintBarCode();

    @VTID(13)
    void defaultPrintBarCode(
        boolean prop);

    @VTID(14)
    boolean defaultPrintFIMA();

    @VTID(15)
    void defaultPrintFIMA(
        boolean prop);

    @VTID(16)
    float defaultHeight();

    @VTID(17)
    void defaultHeight(
        float prop);

    @VTID(18)
    float defaultWidth();

    @VTID(19)
    void defaultWidth(
        float prop);

    @VTID(20)
    @DefaultMethod
    java.lang.String defaultSize();

    @VTID(21)
    @DefaultMethod
    void defaultSize(
        java.lang.String prop);

    @VTID(22)
    boolean defaultOmitReturnAddress();

    @VTID(23)
    void defaultOmitReturnAddress(
        boolean prop);

    @VTID(24)
    mol.word.WdPaperTray feedSource();

    @VTID(25)
    void feedSource(
        mol.word.WdPaperTray prop);

    @VTID(26)
    float addressFromLeft();

    @VTID(27)
    void addressFromLeft(
        float prop);

    @VTID(28)
    float addressFromTop();

    @VTID(29)
    void addressFromTop(
        float prop);

    @VTID(30)
    float returnAddressFromLeft();

    @VTID(31)
    void returnAddressFromLeft(
        float prop);

    @VTID(32)
    float returnAddressFromTop();

    @VTID(33)
    void returnAddressFromTop(
        float prop);

    @VTID(34)
    mol.word.Style addressStyle();

    @VTID(35)
    mol.word.Style returnAddressStyle();

    @VTID(36)
    mol.word.WdEnvelopeOrientation defaultOrientation();

    @VTID(37)
    void defaultOrientation(
        mol.word.WdEnvelopeOrientation prop);

    @VTID(38)
    boolean defaultFaceUp();

    @VTID(39)
    void defaultFaceUp(
        boolean prop);

    @VTID(40)
    void insert2000(
        java.lang.Object extractAddress,
        java.lang.Object address,
        java.lang.Object autoText,
        java.lang.Object omitReturnAddress,
        java.lang.Object returnAddress,
        java.lang.Object returnAutoText,
        java.lang.Object printBarCode,
        java.lang.Object printFIMA,
        java.lang.Object size,
        java.lang.Object height,
        java.lang.Object width,
        java.lang.Object feedSource,
        java.lang.Object addressFromLeft,
        java.lang.Object addressFromTop,
        java.lang.Object returnAddressFromLeft,
        java.lang.Object returnAddressFromTop,
        java.lang.Object defaultFaceUp,
        java.lang.Object defaultOrientation);

    @VTID(41)
    void printOut2000(
        java.lang.Object extractAddress,
        java.lang.Object address,
        java.lang.Object autoText,
        java.lang.Object omitReturnAddress,
        java.lang.Object returnAddress,
        java.lang.Object returnAutoText,
        java.lang.Object printBarCode,
        java.lang.Object printFIMA,
        java.lang.Object size,
        java.lang.Object height,
        java.lang.Object width,
        java.lang.Object feedSource,
        java.lang.Object addressFromLeft,
        java.lang.Object addressFromTop,
        java.lang.Object returnAddressFromLeft,
        java.lang.Object returnAddressFromTop,
        java.lang.Object defaultFaceUp,
        java.lang.Object defaultOrientation);

    @VTID(42)
    void updateDocument();

    @VTID(43)
    void options();

    @VTID(44)
    boolean vertical();

    @VTID(45)
    void vertical(
        boolean prop);

    @VTID(46)
    float recipientNamefromLeft();

    @VTID(47)
    void recipientNamefromLeft(
        float prop);

    @VTID(48)
    float recipientNamefromTop();

    @VTID(49)
    void recipientNamefromTop(
        float prop);

    @VTID(50)
    float recipientPostalfromLeft();

    @VTID(51)
    void recipientPostalfromLeft(
        float prop);

    @VTID(52)
    float recipientPostalfromTop();

    @VTID(53)
    void recipientPostalfromTop(
        float prop);

    @VTID(54)
    float senderNamefromLeft();

    @VTID(55)
    void senderNamefromLeft(
        float prop);

    @VTID(56)
    float senderNamefromTop();

    @VTID(57)
    void senderNamefromTop(
        float prop);

    @VTID(58)
    float senderPostalfromLeft();

    @VTID(59)
    void senderPostalfromLeft(
        float prop);

    @VTID(60)
    float senderPostalfromTop();

    @VTID(61)
    void senderPostalfromTop(
        float prop);

    @VTID(62)
    void insert(
        java.lang.Object extractAddress,
        java.lang.Object address,
        java.lang.Object autoText,
        java.lang.Object omitReturnAddress,
        java.lang.Object returnAddress,
        java.lang.Object returnAutoText,
        java.lang.Object printBarCode,
        java.lang.Object printFIMA,
        java.lang.Object size,
        java.lang.Object height,
        java.lang.Object width,
        java.lang.Object feedSource,
        java.lang.Object addressFromLeft,
        java.lang.Object addressFromTop,
        java.lang.Object returnAddressFromLeft,
        java.lang.Object returnAddressFromTop,
        java.lang.Object defaultFaceUp,
        java.lang.Object defaultOrientation,
        java.lang.Object printEPostage,
        java.lang.Object vertical,
        java.lang.Object recipientNamefromLeft,
        java.lang.Object recipientNamefromTop,
        java.lang.Object recipientPostalfromLeft,
        java.lang.Object recipientPostalfromTop,
        java.lang.Object senderNamefromLeft,
        java.lang.Object senderNamefromTop,
        java.lang.Object senderPostalfromLeft,
        java.lang.Object senderPostalfromTop);

    @VTID(63)
    void printOut(
        java.lang.Object extractAddress,
        java.lang.Object address,
        java.lang.Object autoText,
        java.lang.Object omitReturnAddress,
        java.lang.Object returnAddress,
        java.lang.Object returnAutoText,
        java.lang.Object printBarCode,
        java.lang.Object printFIMA,
        java.lang.Object size,
        java.lang.Object height,
        java.lang.Object width,
        java.lang.Object feedSource,
        java.lang.Object addressFromLeft,
        java.lang.Object addressFromTop,
        java.lang.Object returnAddressFromLeft,
        java.lang.Object returnAddressFromTop,
        java.lang.Object defaultFaceUp,
        java.lang.Object defaultOrientation,
        java.lang.Object printEPostage,
        java.lang.Object vertical,
        java.lang.Object recipientNamefromLeft,
        java.lang.Object recipientNamefromTop,
        java.lang.Object recipientPostalfromLeft,
        java.lang.Object recipientPostalfromTop,
        java.lang.Object senderNamefromLeft,
        java.lang.Object senderNamefromTop,
        java.lang.Object senderPostalfromLeft,
        java.lang.Object senderPostalfromTop);

}
