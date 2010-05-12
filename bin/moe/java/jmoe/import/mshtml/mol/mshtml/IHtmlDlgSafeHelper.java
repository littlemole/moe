package mol.mshtml  ;

import com4j.*;

@IID("{3050F81A-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHtmlDlgSafeHelper extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object choosecolordlg(
        @MarshalAs(NativeType.VARIANT) java.lang.Object initColor);

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object getCharset(
        java.lang.String fontName);

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject fonts();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject blockFormats();

}
