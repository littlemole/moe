package mol.excel  ;

import com4j.*;

@IID("{00024471-0001-0000-C000-000000000046}")
public interface IListObject extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void delete();

    @VTID(11)
    java.lang.String publish(
        @MarshalAs(NativeType.VARIANT) java.lang.Object target,
        boolean linkSource);

    @VTID(12)
    void refresh();

    @VTID(13)
    void unlink();

    @VTID(14)
    void unlist();

    @VTID(15)
    void updateChanges(
        mol.excel.XlListConflict iConflictType);

    @VTID(16)
    void resize(
        mol.excel.Range range);

    @VTID(17)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(18)
    boolean active();

    @VTID(19)
    mol.excel.Range dataBodyRange();

    @VTID(20)
    boolean displayRightToLeft();

    @VTID(21)
    mol.excel.Range headerRowRange();

    @VTID(22)
    mol.excel.Range insertRowRange();

    @VTID(23)
    mol.excel.ListColumns listColumns();

    @VTID(24)
    mol.excel.ListRows listRows();

    @VTID(25)
    java.lang.String name();

    @VTID(26)
    void name(
        java.lang.String rhs);

    @VTID(27)
    com4j.Com4jObject queryTable();

    @VTID(28)
    mol.excel.Range range();

    @VTID(29)
    boolean showAutoFilter();

    @VTID(30)
    void showAutoFilter(
        boolean rhs);

    @VTID(31)
    boolean showTotals();

    @VTID(32)
    void showTotals(
        boolean rhs);

    @VTID(33)
    mol.excel.XlListObjectSourceType sourceType();

    @VTID(34)
    mol.excel.Range totalsRowRange();

    @VTID(35)
    java.lang.String sharePointURL();

    @VTID(36)
    mol.excel.XmlMap xmlMap();

    @VTID(37)
    java.lang.String displayName();

    @VTID(38)
    void displayName(
        java.lang.String rhs);

    @VTID(39)
    boolean showHeaders();

    @VTID(40)
    void showHeaders(
        boolean rhs);

    @VTID(41)
    mol.excel.AutoFilter autoFilter();

    @VTID(42)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object tableStyle();

    @VTID(43)
    void tableStyle(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(44)
    boolean showTableStyleFirstColumn();

    @VTID(45)
    void showTableStyleFirstColumn(
        boolean rhs);

    @VTID(46)
    boolean showTableStyleLastColumn();

    @VTID(47)
    void showTableStyleLastColumn(
        boolean rhs);

    @VTID(48)
    boolean showTableStyleRowStripes();

    @VTID(49)
    void showTableStyleRowStripes(
        boolean rhs);

    @VTID(50)
    boolean showTableStyleColumnStripes();

    @VTID(51)
    void showTableStyleColumnStripes(
        boolean rhs);

    @VTID(52)
    mol.excel.Sort sort();

    @VTID(53)
    java.lang.String comment();

    @VTID(54)
    void comment(
        java.lang.String rhs);

    @VTID(55)
    void exportToVisio();

}
