package mol.excel  ;

import com4j.*;

@IID("{0002443D-0001-0000-C000-000000000046}")
public interface ITextFrame extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    float marginBottom();

    @VTID(11)
    void marginBottom(
        float rhs);

    @VTID(12)
    float marginLeft();

    @VTID(13)
    void marginLeft(
        float rhs);

    @VTID(14)
    float marginRight();

    @VTID(15)
    void marginRight(
        float rhs);

    @VTID(16)
    float marginTop();

    @VTID(17)
    void marginTop(
        float rhs);

    @VTID(18)
    mol.office.MsoTextOrientation orientation();

    @VTID(19)
    void orientation(
        mol.office.MsoTextOrientation rhs);

    @VTID(20)
    mol.excel.Characters characters(
        @MarshalAs(NativeType.VARIANT) java.lang.Object start,
        @MarshalAs(NativeType.VARIANT) java.lang.Object length);

    @VTID(21)
    mol.excel.XlHAlign horizontalAlignment();

    @VTID(22)
    void horizontalAlignment(
        mol.excel.XlHAlign rhs);

    @VTID(23)
    mol.excel.XlVAlign verticalAlignment();

    @VTID(24)
    void verticalAlignment(
        mol.excel.XlVAlign rhs);

    @VTID(25)
    boolean autoSize();

    @VTID(26)
    void autoSize(
        boolean rhs);

    @VTID(27)
    int readingOrder();

    @VTID(28)
    void readingOrder(
        int rhs);

    @VTID(29)
    boolean autoMargins();

    @VTID(30)
    void autoMargins(
        boolean rhs);

}
