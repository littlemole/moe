package mol.mshtml  ;

import com4j.*;

@IID("{3050F369-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLBGsound extends Com4jObject {
    @VTID(7)
    void src(
        java.lang.String p);

    @VTID(8)
    java.lang.String src();

    @VTID(9)
    void loop(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object loop();

    @VTID(11)
    void volume(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object volume();

    @VTID(13)
    void balance(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object balance();

}
