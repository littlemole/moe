package mol.word  ;

import com4j.*;

@IID("{000209C0-0000-0000-C000-000000000046}")
public interface ListFormat extends Com4jObject {
    @VTID(7)
    int listLevelNumber();

    @VTID(8)
    void listLevelNumber(
        int prop);

    @VTID(9)
    mol.word.List list();

    @VTID(10)
    mol.word.ListTemplate listTemplate();

    @VTID(11)
    int listValue();

    @VTID(12)
    boolean singleList();

    @VTID(13)
    boolean singleListTemplate();

    @VTID(14)
    mol.word.WdListType listType();

    @VTID(15)
    java.lang.String listString();

    @VTID(16)
    mol.word._Application application();

    @VTID(17)
    int creator();

    @VTID(18)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(19)
    mol.word.WdContinue canContinuePreviousList(
        mol.word.ListTemplate listTemplate);

    @VTID(20)
    void removeNumbers(
        java.lang.Object numberType);

    @VTID(21)
    void convertNumbersToText(
        java.lang.Object numberType);

    @VTID(22)
    int countNumberedItems(
        java.lang.Object numberType,
        java.lang.Object level);

    @VTID(23)
    void applyBulletDefaultOld();

    @VTID(24)
    void applyNumberDefaultOld();

    @VTID(25)
    void applyOutlineNumberDefaultOld();

    @VTID(26)
    void applyListTemplateOld(
        mol.word.ListTemplate listTemplate,
        java.lang.Object continuePreviousList,
        java.lang.Object applyTo);

    @VTID(27)
    void listOutdent();

    @VTID(28)
    void listIndent();

    @VTID(29)
    void applyBulletDefault(
        java.lang.Object defaultListBehavior);

    @VTID(30)
    void applyNumberDefault(
        java.lang.Object defaultListBehavior);

    @VTID(31)
    void applyOutlineNumberDefault(
        java.lang.Object defaultListBehavior);

    @VTID(32)
    void applyListTemplate(
        mol.word.ListTemplate listTemplate,
        java.lang.Object continuePreviousList,
        java.lang.Object applyTo,
        java.lang.Object defaultListBehavior);

    @VTID(33)
    mol.word.InlineShape listPictureBullet();

    @VTID(34)
    void applyListTemplateWithLevel(
        mol.word.ListTemplate listTemplate,
        java.lang.Object continuePreviousList,
        java.lang.Object applyTo,
        java.lang.Object defaultListBehavior,
        java.lang.Object applyLevel);

}
