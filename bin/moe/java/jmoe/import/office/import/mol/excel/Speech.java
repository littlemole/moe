package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface Speech extends Com4jObject {
    @DISPID(2017)
    void speak(
        java.lang.String text,
        java.lang.Object speakAsync,
        java.lang.Object speakXML,
        java.lang.Object purge);

    @DISPID(168)
    @PropGet
    mol.excel.XlSpeakDirection direction();

    @DISPID(168)
    @PropPut
    void direction(
        mol.excel.XlSpeakDirection rhs);

    @DISPID(2235)
    @PropGet
    boolean speakCellOnEnter();

    @DISPID(2235)
    @PropPut
    void speakCellOnEnter(
        boolean rhs);

}
