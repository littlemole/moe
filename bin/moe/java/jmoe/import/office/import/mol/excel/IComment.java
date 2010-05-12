package mol.excel  ;

import com4j.*;

@IID("{00024427-0001-0000-C000-000000000046}")
public interface IComment extends Com4jObject {
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
    mol.excel.Shape shape();

    @VTID(12)
    boolean visible();

    @VTID(13)
    void visible(
        boolean rhs);

    @VTID(14)
    java.lang.String text(
        @MarshalAs(NativeType.VARIANT) java.lang.Object text,
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object overwrite);

    @VTID(15)
    void delete();

    @VTID(16)
    mol.excel.Comment next();

    @VTID(17)
    mol.excel.Comment previous();

}
