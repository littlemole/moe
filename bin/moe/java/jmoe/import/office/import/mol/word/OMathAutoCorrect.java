package mol.word  ;

import com4j.*;

@IID("{6F9D1F68-06F7-49EF-8902-185E54EB5E87}")
public interface OMathAutoCorrect extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean replaceText();

    @VTID(11)
    void replaceText(
        boolean prop);

    @VTID(12)
    boolean useOutsideOMath();

    @VTID(13)
    void useOutsideOMath(
        boolean prop);

    @VTID(14)
    mol.word.OMathAutoCorrectEntries entries();

    @VTID(14)
    @ReturnValue(defaultPropertyThrough={mol.word.OMathAutoCorrectEntries.class})
    mol.word.OMathAutoCorrectEntry entries(
        java.lang.Object index);

    @VTID(15)
    mol.word.OMathRecognizedFunctions functions();

    @VTID(15)
    @ReturnValue(defaultPropertyThrough={mol.word.OMathRecognizedFunctions.class})
    mol.word.OMathRecognizedFunction functions(
        java.lang.Object index);

}
