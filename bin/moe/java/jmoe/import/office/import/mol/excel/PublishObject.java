package mol.excel  ;

import com4j.*;

@IID("{00024444-0000-0000-C000-000000000046}")
public interface PublishObject extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void delete();

    @VTID(11)
    void publish(
        @MarshalAs(NativeType.VARIANT) java.lang.Object create);

    @VTID(12)
    java.lang.String divID();

    @VTID(13)
    java.lang.String sheet();

    @VTID(14)
    mol.excel.XlSourceType sourceType();

    @VTID(15)
    java.lang.String source();

    @VTID(16)
    mol.excel.XlHtmlType htmlType();

    @VTID(17)
    void htmlType(
        mol.excel.XlHtmlType rhs);

    @VTID(18)
    java.lang.String title();

    @VTID(19)
    void title(
        java.lang.String rhs);

    @VTID(20)
    java.lang.String filename();

    @VTID(21)
    void filename(
        java.lang.String rhs);

    @VTID(22)
    boolean autoRepublish();

    @VTID(23)
    void autoRepublish(
        boolean rhs);

}
