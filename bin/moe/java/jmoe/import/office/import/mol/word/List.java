package mol.word  ;

import com4j.*;

@IID("{00020992-0000-0000-C000-000000000046}")
public interface List extends Com4jObject {
    @VTID(7)
    mol.word.Range range();

    @VTID(8)
    mol.word.ListParagraphs listParagraphs();

    @VTID(8)
    @ReturnValue(defaultPropertyThrough={mol.word.ListParagraphs.class})
    mol.word.Paragraph listParagraphs(
        int index);

    @VTID(9)
    boolean singleListTemplate();

    @VTID(10)
    mol.word._Application application();

    @VTID(11)
    int creator();

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(13)
    void convertNumbersToText(
        java.lang.Object numberType);

    @VTID(14)
    void removeNumbers(
        java.lang.Object numberType);

    @VTID(15)
    int countNumberedItems(
        java.lang.Object numberType,
        java.lang.Object level);

    @VTID(16)
    void applyListTemplateOld(
        mol.word.ListTemplate listTemplate,
        java.lang.Object continuePreviousList);

    @VTID(17)
    mol.word.WdContinue canContinuePreviousList(
        mol.word.ListTemplate listTemplate);

    @VTID(18)
    void applyListTemplate(
        mol.word.ListTemplate listTemplate,
        java.lang.Object continuePreviousList,
        java.lang.Object defaultListBehavior);

    @VTID(19)
    java.lang.String styleName();

    @VTID(20)
    void applyListTemplateWithLevel(
        mol.word.ListTemplate listTemplate,
        java.lang.Object continuePreviousList,
        java.lang.Object defaultListBehavior,
        java.lang.Object applyLevel);

}
