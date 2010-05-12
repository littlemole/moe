package mol.excel  ;

import com4j.*;

@IID("{00020857-0001-0000-C000-000000000046}")
public interface IAddIn extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String author();

    @VTID(11)
    java.lang.String comments();

    @VTID(12)
    java.lang.String fullName();

    @VTID(13)
    boolean installed();

    @VTID(14)
    void installed(
        boolean rhs);

    @VTID(15)
    java.lang.String keywords();

    @VTID(16)
    java.lang.String name();

    @VTID(17)
    java.lang.String path();

    @VTID(18)
    java.lang.String subject();

    @VTID(19)
    java.lang.String title();

    @VTID(20)
    java.lang.String progID();

    @VTID(21)
    java.lang.String clsid();

}
