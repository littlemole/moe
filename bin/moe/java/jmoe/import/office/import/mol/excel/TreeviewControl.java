package mol.excel  ;

import com4j.*;

@IID("{0002444B-0000-0000-C000-000000000046}")
public interface TreeviewControl extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object hidden();

    @VTID(11)
    void hidden(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object drilled();

    @VTID(13)
    void drilled(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

}
