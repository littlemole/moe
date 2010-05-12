package mol.excel  ;

import com4j.*;

@IID("{00024450-0001-0000-C000-000000000046}")
public interface ICellFormat extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.Borders borders();

    @VTID(11)
    void borders(
        mol.excel.Borders rhs);

    @VTID(12)
    mol.excel.Font font();

    @VTID(13)
    void font(
        mol.excel.Font rhs);

    @VTID(14)
    mol.excel.Interior interior();

    @VTID(15)
    void interior(
        mol.excel.Interior rhs);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormat(
        int lcid);

    @VTID(17)
    void numberFormat(
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object numberFormatLocal();

    @VTID(19)
    void numberFormatLocal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(20)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object addIndent();

    @VTID(21)
    void addIndent(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object indentLevel();

    @VTID(23)
    void indentLevel(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(24)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object horizontalAlignment();

    @VTID(25)
    void horizontalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object verticalAlignment();

    @VTID(27)
    void verticalAlignment(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(28)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object orientation();

    @VTID(29)
    void orientation(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(30)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object shrinkToFit();

    @VTID(31)
    void shrinkToFit(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(32)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object wrapText();

    @VTID(33)
    void wrapText(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object locked();

    @VTID(35)
    void locked(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(36)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object formulaHidden();

    @VTID(37)
    void formulaHidden(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(38)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object mergeCells();

    @VTID(39)
    void mergeCells(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(40)
    void clear();

}
