package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface UniqueValues extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(985)
    @PropGet
    int priority();

    @DISPID(985)
    @PropPut
    void priority(
        int rhs);

    @DISPID(2625)
    @PropGet
    boolean stopIfTrue();

    @DISPID(2625)
    @PropPut
    void stopIfTrue(
        boolean rhs);

    @DISPID(2626)
    @PropGet
    mol.excel.Range appliesTo();

    @DISPID(2733)
    @PropGet
    mol.excel.XlDupeUnique dupeUnique();

    @DISPID(2733)
    @PropPut
    void dupeUnique(
        mol.excel.XlDupeUnique rhs);

    @DISPID(129)
    @PropGet
    mol.excel.Interior interior();

    @DISPID(435)
    @PropGet
    mol.excel.Borders borders();

    @DISPID(146)
    @PropGet
    mol.excel.Font font();

    @DISPID(108)
    @PropGet
    int type();

    @DISPID(193)
    @PropGet
    java.lang.Object numberFormat();

    @DISPID(193)
    @PropPut
    void numberFormat(
        java.lang.Object rhs);

    @DISPID(2629)
    void setFirstPriority();

    @DISPID(2630)
    void setLastPriority();

    @DISPID(117)
    void delete();

    @DISPID(2627)
    void modifyAppliesToRange(
        mol.excel.Range range);

    @DISPID(2631)
    @PropGet
    boolean ptCondition();

    @DISPID(2615)
    @PropGet
    mol.excel.XlPivotConditionScope scopeType();

    @DISPID(2615)
    @PropPut
    void scopeType(
        mol.excel.XlPivotConditionScope rhs);

}
