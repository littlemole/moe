package mol.office  ;

import com4j.*;

@IID("{000C171B-0000-0000-C000-000000000046}")
public interface IMsoInterior extends Com4jObject {
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
    void invertIfNegative(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pval);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object invertIfNegative();

    @VTID(13)
    void pattern(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pval);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object pattern();

    @VTID(15)
    void patternColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pval);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object patternColor();

    @VTID(17)
    void patternColorIndex(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pval);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object patternColorIndex();

}
