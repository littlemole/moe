package mol.mshtml  ;

import com4j.*;

@IID("{3050F230-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLTextContainer extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject createControlRange();

    @VTID(8)
    int scrollHeight();

    @VTID(9)
    int scrollWidth();

    @VTID(10)
    void scrollTop(
        int p);

    @VTID(11)
    int scrollTop();

    @VTID(12)
    void scrollLeft(
        int p);

    @VTID(13)
    int scrollLeft();

    @VTID(14)
    void onscroll(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object onscroll();

}
