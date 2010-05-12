package mol.mshtml  ;

import com4j.*;

@IID("{3050F4B3-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLDataTransfer extends Com4jObject {
    @VTID(7)
    boolean setData(
        java.lang.String format,
        java.lang.Object data);

    @VTID(8)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object getData(
        java.lang.String format);

    @VTID(9)
    boolean clearData(
        java.lang.String format);

    @VTID(10)
    void dropEffect(
        java.lang.String p);

    @VTID(11)
    java.lang.String dropEffect();

    @VTID(12)
    void effectAllowed(
        java.lang.String p);

    @VTID(13)
    java.lang.String effectAllowed();

}
