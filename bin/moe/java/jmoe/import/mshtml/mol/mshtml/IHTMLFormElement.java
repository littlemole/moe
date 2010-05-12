package mol.mshtml  ;

import com4j.*;

@IID("{3050F1F7-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLFormElement extends Com4jObject {
    @VTID(7)
    void action(
        java.lang.String p);

    @VTID(8)
    java.lang.String action();

    @VTID(9)
    void dir(
        java.lang.String p);

    @VTID(10)
    java.lang.String dir();

    @VTID(11)
    void encoding(
        java.lang.String p);

    @VTID(12)
    java.lang.String encoding();

    @VTID(13)
    void method(
        java.lang.String p);

    @VTID(14)
    java.lang.String method();

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject elements();

    @VTID(16)
    void target(
        java.lang.String p);

    @VTID(17)
    java.lang.String target();

    @VTID(18)
    void name(
        java.lang.String p);

    @VTID(19)
    java.lang.String name();

    @VTID(20)
    void onsubmit(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onsubmit();

    @VTID(22)
    void onreset(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(23)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onreset();

    @VTID(24)
    void submit();

    @VTID(25)
    void reset();

    @VTID(26)
    void length(
        int p);

    @VTID(27)
    int length();

    @VTID(28)
    com4j.Com4jObject _newEnum();

    @VTID(29)
    @DefaultMethod
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(30)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject tags(
        @MarshalAs(NativeType.VARIANT) java.lang.Object tagName);

}
