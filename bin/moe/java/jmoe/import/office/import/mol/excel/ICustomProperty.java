package mol.excel  ;

import com4j.*;

@IID("{00024453-0001-0000-C000-000000000046}")
public interface ICustomProperty extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    void name(
        java.lang.String rhs);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value();

    @VTID(13)
    void value(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(14)
    @DefaultMethod
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _Default();

    @VTID(15)
    void delete();

}
