package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface IconSetCondition extends Com4jObject {
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

    @DISPID(2626)
    @PropGet
    mol.excel.Range appliesTo();

    @DISPID(108)
    @PropGet
    int type();

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

    @DISPID(2629)
    void setFirstPriority();

    @DISPID(2630)
    void setLastPriority();

    @DISPID(117)
    void delete();

    @DISPID(2723)
    @PropGet
    boolean reverseOrder();

    @DISPID(2723)
    @PropPut
    void reverseOrder(
        boolean rhs);

    @DISPID(2724)
    @PropGet
    boolean percentileValues();

    @DISPID(2724)
    @PropPut
    void percentileValues(
        boolean rhs);

    @DISPID(2725)
    @PropGet
    boolean showIconOnly();

    @DISPID(2725)
    @PropPut
    void showIconOnly(
        boolean rhs);

    @DISPID(261)
    @PropGet
    java.lang.String formula();

    @DISPID(261)
    @PropPut
    void formula(
        java.lang.String rhs);

    @DISPID(2726)
    @PropGet
    java.lang.Object iconSet();

    @DISPID(2726)
    @PropPut
    void iconSet(
        java.lang.Object rhs);

    @DISPID(2727)
    @PropGet
    mol.excel.IconCriteria iconCriteria();

}
