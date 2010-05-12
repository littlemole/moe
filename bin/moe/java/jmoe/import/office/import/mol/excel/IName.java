package mol.excel  ;

import com4j.*;

@IID("{000208B9-0001-0000-C000-000000000046}")
public interface IName extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(11)
    int index();

    @VTID(12)
    java.lang.String category(
        int lcidIn);

    @VTID(13)
    void category(
        int lcidIn,
        java.lang.String rhs);

    @VTID(14)
    java.lang.String categoryLocal();

    @VTID(15)
    void categoryLocal(
        java.lang.String rhs);

    @VTID(16)
    void delete();

    @VTID(17)
    mol.excel.XlXLMMacroType macroType();

    @VTID(18)
    void macroType(
        mol.excel.XlXLMMacroType rhs);

    @VTID(19)
    java.lang.String name(
        int lcidIn);

    @VTID(20)
    void name(
        int lcidIn,
        java.lang.String rhs);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object refersTo(
        int lcidIn);

    @VTID(22)
    void refersTo(
        int lcidIn,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(23)
    java.lang.String shortcutKey();

    @VTID(24)
    void shortcutKey(
        java.lang.String rhs);

    @VTID(25)
    java.lang.String value();

    @VTID(26)
    void value(
        java.lang.String rhs);

    @VTID(27)
    boolean visible();

    @VTID(28)
    void visible(
        boolean rhs);

    @VTID(29)
    java.lang.String nameLocal();

    @VTID(30)
    void nameLocal(
        java.lang.String rhs);

    @VTID(31)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object refersToLocal();

    @VTID(32)
    void refersToLocal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(33)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object refersToR1C1(
        int lcidIn);

    @VTID(34)
    void refersToR1C1(
        int lcidIn,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(35)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object refersToR1C1Local();

    @VTID(36)
    void refersToR1C1Local(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(37)
    mol.excel.Range refersToRange();

    @VTID(38)
    java.lang.String comment();

    @VTID(39)
    void comment(
        java.lang.String rhs);

    @VTID(40)
    boolean workbookParameter();

    @VTID(41)
    void workbookParameter(
        boolean rhs);

    @VTID(42)
    boolean validWorkbookParameter();

}
