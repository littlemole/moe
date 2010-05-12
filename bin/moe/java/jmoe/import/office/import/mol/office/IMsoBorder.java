package mol.office  ;

import com4j.*;

@IID("{000C1717-0000-0000-C000-000000000046}")
public interface IMsoBorder extends Com4jObject {
    @VTID(7)
    void color(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pval);

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object color();

    @VTID(9)
    void colorIndex(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pval);

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object colorIndex();

    @VTID(11)
    void lineStyle(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pval);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object lineStyle();

    @VTID(13)
    void weight(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pval);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object weight();

}
