package mol.excel  ;

import com4j.*;

@IID("{000208D4-0001-0000-C000-000000000046}")
public interface IAutoCorrect extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object addReplacement(
        java.lang.String what,
        java.lang.String replacement);

    @VTID(11)
    boolean capitalizeNamesOfDays();

    @VTID(12)
    void capitalizeNamesOfDays(
        boolean rhs);

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object deleteReplacement(
        java.lang.String what);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object replacementList(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(15)
    void replacementList(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(16)
    boolean replaceText();

    @VTID(17)
    void replaceText(
        boolean rhs);

    @VTID(18)
    boolean twoInitialCapitals();

    @VTID(19)
    void twoInitialCapitals(
        boolean rhs);

    @VTID(20)
    boolean correctSentenceCap();

    @VTID(21)
    void correctSentenceCap(
        boolean rhs);

    @VTID(22)
    boolean correctCapsLock();

    @VTID(23)
    void correctCapsLock(
        boolean rhs);

    @VTID(24)
    boolean displayAutoCorrectOptions();

    @VTID(25)
    void displayAutoCorrectOptions(
        boolean rhs);

    @VTID(26)
    boolean autoExpandListRange();

    @VTID(27)
    void autoExpandListRange(
        boolean rhs);

    @VTID(28)
    boolean autoFillFormulasInLists();

    @VTID(29)
    void autoFillFormulasInLists(
        boolean rhs);

}
