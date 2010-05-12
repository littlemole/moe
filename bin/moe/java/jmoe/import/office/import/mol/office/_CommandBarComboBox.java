package mol.office  ;

import com4j.*;

@IID("{000C030C-0000-0000-C000-000000000046}")
public interface _CommandBarComboBox extends mol.office.CommandBarControl {
    @VTID(83)
    void addItem(
        java.lang.String text,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(84)
    void clear();

    @VTID(85)
    int dropDownLines();

    @VTID(86)
    void dropDownLines(
        int pcLines);

    @VTID(87)
    int dropDownWidth();

    @VTID(88)
    void dropDownWidth(
        int pdx);

    @VTID(89)
    java.lang.String list(
        int index);

    @VTID(90)
    void list(
        int index,
        java.lang.String pbstrItem);

    @VTID(91)
    int listCount();

    @VTID(92)
    int listHeaderCount();

    @VTID(93)
    void listHeaderCount(
        int pcItems);

    @VTID(94)
    int listIndex();

    @VTID(95)
    void listIndex(
        int pi);

    @VTID(96)
    void removeItem(
        int index);

    @VTID(97)
    mol.office.MsoComboStyle style();

    @VTID(98)
    void style(
        mol.office.MsoComboStyle pstyle);

    @VTID(99)
    java.lang.String text();

    @VTID(100)
    void text(
        java.lang.String pbstrText);

}
