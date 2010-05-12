package mol.word  ;

import com4j.*;

@IID("{000209A1-0000-0000-C000-000000000046}")
public interface _LetterContent extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word._LetterContent duplicate();

    @VTID(11)
    java.lang.String dateFormat();

    @VTID(12)
    void dateFormat(
        java.lang.String prop);

    @VTID(13)
    boolean includeHeaderFooter();

    @VTID(14)
    void includeHeaderFooter(
        boolean prop);

    @VTID(15)
    java.lang.String pageDesign();

    @VTID(16)
    void pageDesign(
        java.lang.String prop);

    @VTID(17)
    mol.word.WdLetterStyle letterStyle();

    @VTID(18)
    void letterStyle(
        mol.word.WdLetterStyle prop);

    @VTID(19)
    boolean letterhead();

    @VTID(20)
    void letterhead(
        boolean prop);

    @VTID(21)
    mol.word.WdLetterheadLocation letterheadLocation();

    @VTID(22)
    void letterheadLocation(
        mol.word.WdLetterheadLocation prop);

    @VTID(23)
    float letterheadSize();

    @VTID(24)
    void letterheadSize(
        float prop);

    @VTID(25)
    java.lang.String recipientName();

    @VTID(26)
    void recipientName(
        java.lang.String prop);

    @VTID(27)
    java.lang.String recipientAddress();

    @VTID(28)
    void recipientAddress(
        java.lang.String prop);

    @VTID(29)
    java.lang.String salutation();

    @VTID(30)
    void salutation(
        java.lang.String prop);

    @VTID(31)
    mol.word.WdSalutationType salutationType();

    @VTID(32)
    void salutationType(
        mol.word.WdSalutationType prop);

    @VTID(33)
    java.lang.String recipientReference();

    @VTID(34)
    void recipientReference(
        java.lang.String prop);

    @VTID(35)
    java.lang.String mailingInstructions();

    @VTID(36)
    void mailingInstructions(
        java.lang.String prop);

    @VTID(37)
    java.lang.String attentionLine();

    @VTID(38)
    void attentionLine(
        java.lang.String prop);

    @VTID(39)
    java.lang.String subject();

    @VTID(40)
    void subject(
        java.lang.String prop);

    @VTID(41)
    int enclosureNumber();

    @VTID(42)
    void enclosureNumber(
        int prop);

    @VTID(43)
    java.lang.String ccList();

    @VTID(44)
    void ccList(
        java.lang.String prop);

    @VTID(45)
    java.lang.String returnAddress();

    @VTID(46)
    void returnAddress(
        java.lang.String prop);

    @VTID(47)
    java.lang.String senderName();

    @VTID(48)
    void senderName(
        java.lang.String prop);

    @VTID(49)
    java.lang.String closing();

    @VTID(50)
    void closing(
        java.lang.String prop);

    @VTID(51)
    java.lang.String senderCompany();

    @VTID(52)
    void senderCompany(
        java.lang.String prop);

    @VTID(53)
    java.lang.String senderJobTitle();

    @VTID(54)
    void senderJobTitle(
        java.lang.String prop);

    @VTID(55)
    java.lang.String senderInitials();

    @VTID(56)
    void senderInitials(
        java.lang.String prop);

    @VTID(57)
    boolean infoBlock();

    @VTID(58)
    void infoBlock(
        boolean prop);

    @VTID(59)
    java.lang.String recipientCode();

    @VTID(60)
    void recipientCode(
        java.lang.String prop);

    @VTID(61)
    mol.word.WdSalutationGender recipientGender();

    @VTID(62)
    void recipientGender(
        mol.word.WdSalutationGender prop);

    @VTID(63)
    java.lang.String returnAddressShortForm();

    @VTID(64)
    void returnAddressShortForm(
        java.lang.String prop);

    @VTID(65)
    java.lang.String senderCity();

    @VTID(66)
    void senderCity(
        java.lang.String prop);

    @VTID(67)
    java.lang.String senderCode();

    @VTID(68)
    void senderCode(
        java.lang.String prop);

    @VTID(69)
    mol.word.WdSalutationGender senderGender();

    @VTID(70)
    void senderGender(
        mol.word.WdSalutationGender prop);

    @VTID(71)
    java.lang.String senderReference();

    @VTID(72)
    void senderReference(
        java.lang.String prop);

}
