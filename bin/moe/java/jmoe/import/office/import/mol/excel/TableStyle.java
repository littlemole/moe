package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface TableStyle extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(937)
    @PropGet
    java.lang.String nameLocal();

    @DISPID(553)
    @PropGet
    boolean builtIn();

    @DISPID(2737)
    @PropGet
    mol.excel.TableStyleElements tableStyleElements();

    @DISPID(2738)
    @PropGet
    boolean showAsAvailableTableStyle();

    @DISPID(2738)
    @PropPut
    void showAsAvailableTableStyle(
        boolean rhs);

    @DISPID(2739)
    @PropGet
    boolean showAsAvailablePivotTableStyle();

    @DISPID(2739)
    @PropPut
    void showAsAvailablePivotTableStyle(
        boolean rhs);

    @DISPID(117)
    void delete();

    @DISPID(1039)
    mol.excel.TableStyle duplicate(
        java.lang.Object newTableStyleName);

}
