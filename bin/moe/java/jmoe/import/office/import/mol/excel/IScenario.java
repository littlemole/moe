package mol.excel  ;

import com4j.*;

@IID("{00020897-0001-0000-C000-000000000046}")
public interface IScenario extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object changeScenario(
        @MarshalAs(NativeType.VARIANT) java.lang.Object changingCells,
        @MarshalAs(NativeType.VARIANT) java.lang.Object values);

    @VTID(11)
    mol.excel.Range changingCells();

    @VTID(12)
    java.lang.String comment();

    @VTID(13)
    void comment(
        java.lang.String rhs);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(15)
    boolean hidden();

    @VTID(16)
    void hidden(
        boolean rhs);

    @VTID(17)
    int index();

    @VTID(18)
    boolean locked();

    @VTID(19)
    void locked(
        boolean rhs);

    @VTID(20)
    java.lang.String name();

    @VTID(21)
    void name(
        java.lang.String rhs);

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object show();

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object values(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
