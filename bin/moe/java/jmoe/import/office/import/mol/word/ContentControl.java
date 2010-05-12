package mol.word  ;

import com4j.*;

@IID("{EE95AFE3-3026-4172-B078-0E79DAB5CC3D}")
public interface ContentControl extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.Range range();

    @VTID(11)
    boolean lockContentControl();

    @VTID(12)
    void lockContentControl(
        boolean prop);

    @VTID(13)
    boolean lockContents();

    @VTID(14)
    void lockContents(
        boolean prop);

    @VTID(15)
    mol.word.XMLMapping xmlMapping();

    @VTID(16)
    mol.word.WdContentControlType type();

    @VTID(17)
    void type(
        mol.word.WdContentControlType prop);

    @VTID(18)
    void copy();

    @VTID(19)
    void cut();

    @VTID(20)
    void delete(
        boolean deleteContents);

    @VTID(21)
    mol.word.ContentControlListEntries dropdownListEntries();

    @VTID(21)
    @ReturnValue(defaultPropertyThrough={mol.word.ContentControlListEntries.class})
    mol.word.ContentControlListEntry dropdownListEntries(
        int index);

    @VTID(22)
    mol.word.BuildingBlock placeholderText();

    @VTID(23)
    void setPlaceholderText(
        mol.word.BuildingBlock buildingBlock,
        mol.word.Range range,
        java.lang.String text);

    @VTID(24)
    java.lang.String title();

    @VTID(25)
    void title(
        java.lang.String prop);

    @VTID(26)
    java.lang.String dateDisplayFormat();

    @VTID(27)
    void dateDisplayFormat(
        java.lang.String prop);

    @VTID(28)
    boolean multiLine();

    @VTID(29)
    void multiLine(
        boolean prop);

    @VTID(30)
    mol.word.ContentControl parentContentControl();

    @VTID(31)
    boolean temporary();

    @VTID(32)
    void temporary(
        boolean prop);

    @VTID(33)
    java.lang.String id();

    @VTID(34)
    boolean showingPlaceholderText();

    @VTID(35)
    mol.word.WdContentControlDateStorageFormat dateStorageFormat();

    @VTID(36)
    void dateStorageFormat(
        mol.word.WdContentControlDateStorageFormat prop);

    @VTID(37)
    mol.word.WdBuildingBlockTypes buildingBlockType();

    @VTID(38)
    void buildingBlockType(
        mol.word.WdBuildingBlockTypes prop);

    @VTID(39)
    java.lang.String buildingBlockCategory();

    @VTID(40)
    void buildingBlockCategory(
        java.lang.String prop);

    @VTID(41)
    mol.word.WdLanguageID dateDisplayLocale();

    @VTID(42)
    void dateDisplayLocale(
        mol.word.WdLanguageID prop);

    @VTID(43)
    void ungroup();

    @VTID(44)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object defaultTextStyle();

    @VTID(45)
    void defaultTextStyle(
        java.lang.Object prop);

    @VTID(46)
    mol.word.WdCalendarType dateCalendarType();

    @VTID(47)
    void dateCalendarType(
        mol.word.WdCalendarType prop);

    @VTID(48)
    java.lang.String tag();

    @VTID(49)
    void tag(
        java.lang.String prop);

}
