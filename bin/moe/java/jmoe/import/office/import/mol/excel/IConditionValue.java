package mol.excel  ;

import com4j.*;

@IID("{00024492-0001-0000-C000-000000000046}")
public interface IConditionValue extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void modify(
        mol.excel.XlConditionValueTypes newtype,
        @MarshalAs(NativeType.VARIANT) java.lang.Object newvalue);

    @VTID(11)
    mol.excel.XlConditionValueTypes type();

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value();

}
