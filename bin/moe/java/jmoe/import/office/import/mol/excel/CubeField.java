package mol.excel  ;

import com4j.*;

@IID("{0002444C-0000-0000-C000-000000000046}")
public interface CubeField extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.XlCubeFieldType cubeFieldType();

    @VTID(11)
    java.lang.String _Caption();

    @VTID(12)
    java.lang.String name();

    @VTID(13)
    java.lang.String value();

    @VTID(14)
    mol.excel.XlPivotFieldOrientation orientation();

    @VTID(15)
    void orientation(
        mol.excel.XlPivotFieldOrientation rhs);

    @VTID(16)
    int position();

    @VTID(17)
    void position(
        int rhs);

    @VTID(18)
    mol.excel.TreeviewControl treeviewControl();

    @VTID(19)
    boolean dragToColumn();

    @VTID(20)
    void dragToColumn(
        boolean rhs);

    @VTID(21)
    boolean dragToHide();

    @VTID(22)
    void dragToHide(
        boolean rhs);

    @VTID(23)
    boolean dragToPage();

    @VTID(24)
    void dragToPage(
        boolean rhs);

    @VTID(25)
    boolean dragToRow();

    @VTID(26)
    void dragToRow(
        boolean rhs);

    @VTID(27)
    boolean dragToData();

    @VTID(28)
    void dragToData(
        boolean rhs);

    @VTID(29)
    int hiddenLevels();

    @VTID(30)
    void hiddenLevels(
        int rhs);

    @VTID(31)
    boolean hasMemberProperties();

    @VTID(32)
    mol.excel.XlLayoutFormType layoutForm();

    @VTID(33)
    void layoutForm(
        mol.excel.XlLayoutFormType rhs);

    @VTID(34)
    mol.excel.PivotFields pivotFields();

    @VTID(35)
    void _AddMemberPropertyField(
        java.lang.String property,
        @MarshalAs(NativeType.VARIANT) java.lang.Object propertyOrder);

    @VTID(36)
    boolean enableMultiplePageItems();

    @VTID(37)
    void enableMultiplePageItems(
        boolean rhs);

    @VTID(38)
    mol.excel.XlSubtototalLocationType layoutSubtotalLocation();

    @VTID(39)
    void layoutSubtotalLocation(
        mol.excel.XlSubtototalLocationType rhs);

    @VTID(40)
    boolean showInFieldList();

    @VTID(41)
    void showInFieldList(
        boolean rhs);

    @VTID(42)
    void delete();

    @VTID(43)
    void addMemberPropertyField(
        java.lang.String property,
        @MarshalAs(NativeType.VARIANT) java.lang.Object propertyOrder,
        @MarshalAs(NativeType.VARIANT) java.lang.Object propertyDisplayedIn);

    @VTID(44)
    boolean includeNewItemsInFilter();

    @VTID(45)
    void includeNewItemsInFilter(
        boolean rhs);

    @VTID(46)
    mol.excel.XlCubeFieldSubType cubeFieldSubType();

    @VTID(47)
    boolean allItemsVisible();

    @VTID(48)
    void clearManualFilter();

    @VTID(49)
    void createPivotFields();

    @VTID(50)
    java.lang.String currentPageName();

    @VTID(51)
    void currentPageName(
        java.lang.String rhs);

    @VTID(52)
    boolean isDate();

    @VTID(53)
    java.lang.String caption();

    @VTID(54)
    void caption(
        java.lang.String rhs);

}
