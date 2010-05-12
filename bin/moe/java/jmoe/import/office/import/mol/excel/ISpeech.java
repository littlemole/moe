package mol.excel  ;

import com4j.*;

@IID("{00024466-0001-0000-C000-000000000046}")
public interface ISpeech extends Com4jObject {
    @VTID(7)
    void speak(
        java.lang.String text,
        @MarshalAs(NativeType.VARIANT) java.lang.Object speakAsync,
        @MarshalAs(NativeType.VARIANT) java.lang.Object speakXML,
        @MarshalAs(NativeType.VARIANT) java.lang.Object purge);

    @VTID(8)
    mol.excel.XlSpeakDirection direction();

    @VTID(9)
    void direction(
        mol.excel.XlSpeakDirection rhs);

    @VTID(10)
    boolean speakCellOnEnter();

    @VTID(11)
    void speakCellOnEnter(
        boolean rhs);

}
