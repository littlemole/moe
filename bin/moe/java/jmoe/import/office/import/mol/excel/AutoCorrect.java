package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface AutoCorrect extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(1146)
    java.lang.Object addReplacement(
        java.lang.String what,
        java.lang.String replacement);

    @DISPID(1150)
    @PropGet
    boolean capitalizeNamesOfDays();

    @DISPID(1150)
    @PropPut
    void capitalizeNamesOfDays(
        boolean rhs);

    @DISPID(1147)
    java.lang.Object deleteReplacement(
        java.lang.String what);

    @DISPID(1151)
    @PropGet
    java.lang.Object replacementList(
        java.lang.Object index);

    @DISPID(1151)
    @PropPut
    void replacementList(
        java.lang.Object index,
        java.lang.Object rhs);

    @DISPID(1148)
    @PropGet
    boolean replaceText();

    @DISPID(1148)
    @PropPut
    void replaceText(
        boolean rhs);

    @DISPID(1149)
    @PropGet
    boolean twoInitialCapitals();

    @DISPID(1149)
    @PropPut
    void twoInitialCapitals(
        boolean rhs);

    @DISPID(1619)
    @PropGet
    boolean correctSentenceCap();

    @DISPID(1619)
    @PropPut
    void correctSentenceCap(
        boolean rhs);

    @DISPID(1620)
    @PropGet
    boolean correctCapsLock();

    @DISPID(1620)
    @PropPut
    void correctCapsLock(
        boolean rhs);

    @DISPID(1926)
    @PropGet
    boolean displayAutoCorrectOptions();

    @DISPID(1926)
    @PropPut
    void displayAutoCorrectOptions(
        boolean rhs);

    @DISPID(2294)
    @PropGet
    boolean autoExpandListRange();

    @DISPID(2294)
    @PropPut
    void autoExpandListRange(
        boolean rhs);

    @DISPID(2642)
    @PropGet
    boolean autoFillFormulasInLists();

    @DISPID(2642)
    @PropPut
    void autoFillFormulasInLists(
        boolean rhs);

}
