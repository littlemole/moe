package mol.excel  ;

import com4j.*;

@IID("{00020852-0001-0000-C000-000000000046}")
public interface IStyle extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean addIndent();

    @VTID(11)
    void addIndent(
        boolean rhs);

    @VTID(12)
    boolean builtIn();

    @VTID(13)
    mol.excel.Borders borders();

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(15)
    mol.excel.Font font();

    @VTID(16)
    boolean formulaHidden();

    @VTID(17)
    void formulaHidden(
        boolean rhs);

    @VTID(18)
    mol.excel.XlHAlign horizontalAlignment();

    @VTID(19)
    void horizontalAlignment(
        mol.excel.XlHAlign rhs);

    @VTID(20)
    boolean includeAlignment();

    @VTID(21)
    void includeAlignment(
        boolean rhs);

    @VTID(22)
    boolean includeBorder();

    @VTID(23)
    void includeBorder(
        boolean rhs);

    @VTID(24)
    boolean includeFont();

    @VTID(25)
    void includeFont(
        boolean rhs);

    @VTID(26)
    boolean includeNumber();

    @VTID(27)
    void includeNumber(
        boolean rhs);

    @VTID(28)
    boolean includePatterns();

    @VTID(29)
    void includePatterns(
        boolean rhs);

    @VTID(30)
    boolean includeProtection();

    @VTID(31)
    void includeProtection(
        boolean rhs);

    @VTID(32)
    int indentLevel();

    @VTID(33)
    void indentLevel(
        int rhs);

    @VTID(34)
    mol.excel.Interior interior();

    @VTID(35)
    boolean locked();

    @VTID(36)
    void locked(
        boolean rhs);

    @VTID(37)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object mergeCells();

    @VTID(38)
    void mergeCells(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(39)
    java.lang.String name(
        int lcid);

    @VTID(40)
    java.lang.String nameLocal();

    @VTID(41)
    java.lang.String numberFormat();

    @VTID(42)
    void numberFormat(
        java.lang.String rhs);

    @VTID(43)
    java.lang.String numberFormatLocal();

    @VTID(44)
    void numberFormatLocal(
        java.lang.String rhs);

    @VTID(45)
    mol.excel.XlOrientation orientation();

    @VTID(46)
    void orientation(
        mol.excel.XlOrientation rhs);

    @VTID(47)
    boolean shrinkToFit();

    @VTID(48)
    void shrinkToFit(
        boolean rhs);

    @VTID(49)
    java.lang.String value(
        int lcid);

    @VTID(50)
    mol.excel.XlVAlign verticalAlignment();

    @VTID(51)
    void verticalAlignment(
        mol.excel.XlVAlign rhs);

    @VTID(52)
    boolean wrapText();

    @VTID(53)
    void wrapText(
        boolean rhs);

    @VTID(54)
    @DefaultMethod
    java.lang.String _Default(
        int lcid);

    @VTID(55)
    int readingOrder();

    @VTID(56)
    void readingOrder(
        int rhs);

}
