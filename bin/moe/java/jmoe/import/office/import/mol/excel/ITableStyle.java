package mol.excel  ;

import com4j.*;

@IID("{000244A7-0001-0000-C000-000000000046}")
public interface ITableStyle extends Com4jObject {
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
    java.lang.String name();

    @VTID(12)
    java.lang.String nameLocal();

    @VTID(13)
    boolean builtIn();

    @VTID(14)
    mol.excel.TableStyleElements tableStyleElements();

    @VTID(15)
    boolean showAsAvailableTableStyle();

    @VTID(16)
    void showAsAvailableTableStyle(
        boolean rhs);

    @VTID(17)
    boolean showAsAvailablePivotTableStyle();

    @VTID(18)
    void showAsAvailablePivotTableStyle(
        boolean rhs);

    @VTID(19)
    void delete();

    @VTID(20)
    mol.excel.TableStyle duplicate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object newTableStyleName);

}
