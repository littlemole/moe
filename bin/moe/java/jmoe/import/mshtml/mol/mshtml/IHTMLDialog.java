package mol.mshtml  ;

import com4j.*;

@IID("{3050F216-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLDialog extends Com4jObject {
    @VTID(7)
    void dialogTop(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dialogTop();

    @VTID(9)
    void dialogLeft(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dialogLeft();

    @VTID(11)
    void dialogWidth(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dialogWidth();

    @VTID(13)
    void dialogHeight(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dialogHeight();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dialogArguments();

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object menuArguments();

    @VTID(17)
    void returnValue(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object returnValue();

    @VTID(19)
    void close();

    @VTID(20)
    java.lang.String toString_();

}
