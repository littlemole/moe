package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface ControlFormat extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(851)
    void addItem(
        java.lang.String text,
        java.lang.Object index);

    @DISPID(853)
    void removeAllItems();

    @DISPID(852)
    void removeItem(
        int index,
        java.lang.Object count);

    @DISPID(848)
    @PropGet
    int dropDownLines();

    @DISPID(848)
    @PropPut
    void dropDownLines(
        int rhs);

    @DISPID(600)
    @PropGet
    boolean enabled();

    @DISPID(600)
    @PropPut
    void enabled(
        boolean rhs);

    @DISPID(845)
    @PropGet
    int largeChange();

    @DISPID(845)
    @PropPut
    void largeChange(
        int rhs);

    @DISPID(1058)
    @PropGet
    java.lang.String linkedCell();

    @DISPID(1058)
    @PropPut
    void linkedCell(
        java.lang.String rhs);

    @DISPID(861)
    java.lang.Object list(
        java.lang.Object index);

    @DISPID(849)
    @PropGet
    int listCount();

    @DISPID(849)
    @PropPut
    void listCount(
        int rhs);

    @DISPID(847)
    @PropGet
    java.lang.String listFillRange();

    @DISPID(847)
    @PropPut
    void listFillRange(
        java.lang.String rhs);

    @DISPID(850)
    @PropGet
    int listIndex();

    @DISPID(850)
    @PropPut
    void listIndex(
        int rhs);

    @DISPID(616)
    @PropGet
    boolean lockedText();

    @DISPID(616)
    @PropPut
    void lockedText(
        boolean rhs);

    @DISPID(842)
    @PropGet
    int max();

    @DISPID(842)
    @PropPut
    void max(
        int rhs);

    @DISPID(843)
    @PropGet
    int min();

    @DISPID(843)
    @PropPut
    void min(
        int rhs);

    @DISPID(32)
    @PropGet
    int multiSelect();

    @DISPID(32)
    @PropPut
    void multiSelect(
        int rhs);

    @DISPID(618)
    @PropGet
    boolean printObject();

    @DISPID(618)
    @PropPut
    void printObject(
        boolean rhs);

    @DISPID(844)
    @PropGet
    int smallChange();

    @DISPID(844)
    @PropPut
    void smallChange(
        int rhs);

    @DISPID(0)
    @PropGet
    @DefaultMethod
    int _Default();

    @DISPID(0)
    @PropPut
    @DefaultMethod
    void _Default(
        int rhs);

    @DISPID(6)
    @PropGet
    int value();

    @DISPID(6)
    @PropPut
    void value(
        int rhs);

}
