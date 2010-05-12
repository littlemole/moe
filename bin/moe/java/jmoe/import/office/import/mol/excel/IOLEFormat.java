package mol.excel  ;

import com4j.*;

@IID("{00024441-0001-0000-C000-000000000046}")
public interface IOLEFormat extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void activate();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject object();

    @VTID(12)
    java.lang.String progID();

    @VTID(13)
    void verb(
        @MarshalAs(NativeType.VARIANT) java.lang.Object verb);

}
