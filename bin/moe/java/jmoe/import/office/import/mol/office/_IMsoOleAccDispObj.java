package mol.office  ;

import com4j.*;

@IID("{000C0301-0000-0000-C000-000000000046}")
public interface _IMsoOleAccDispObj extends mol.office.IAccessible {
    @VTID(28)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject application();

    @VTID(29)
    int creator();

}
