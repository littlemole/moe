package mol.excel  ;

import com4j.*;

@IID("{00024440-0001-0000-C000-000000000046}")
public interface IControlFormat extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void addItem(
        java.lang.String text,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    void removeAllItems();

    @VTID(12)
    void removeItem(
        int index,
        @MarshalAs(NativeType.VARIANT) java.lang.Object count);

    @VTID(13)
    int dropDownLines();

    @VTID(14)
    void dropDownLines(
        int rhs);

    @VTID(15)
    boolean enabled();

    @VTID(16)
    void enabled(
        boolean rhs);

    @VTID(17)
    int largeChange();

    @VTID(18)
    void largeChange(
        int rhs);

    @VTID(19)
    java.lang.String linkedCell();

    @VTID(20)
    void linkedCell(
        java.lang.String rhs);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object list(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(22)
    int listCount();

    @VTID(23)
    void listCount(
        int rhs);

    @VTID(24)
    java.lang.String listFillRange();

    @VTID(25)
    void listFillRange(
        java.lang.String rhs);

    @VTID(26)
    int listIndex();

    @VTID(27)
    void listIndex(
        int rhs);

    @VTID(28)
    boolean lockedText();

    @VTID(29)
    void lockedText(
        boolean rhs);

    @VTID(30)
    int max();

    @VTID(31)
    void max(
        int rhs);

    @VTID(32)
    int min();

    @VTID(33)
    void min(
        int rhs);

    @VTID(34)
    int multiSelect();

    @VTID(35)
    void multiSelect(
        int rhs);

    @VTID(36)
    boolean printObject();

    @VTID(37)
    void printObject(
        boolean rhs);

    @VTID(38)
    int smallChange();

    @VTID(39)
    void smallChange(
        int rhs);

    @VTID(40)
    @DefaultMethod
    int _Default();

    @VTID(41)
    @DefaultMethod
    void _Default(
        int rhs);

    @VTID(42)
    int value();

    @VTID(43)
    void value(
        int rhs);

}
