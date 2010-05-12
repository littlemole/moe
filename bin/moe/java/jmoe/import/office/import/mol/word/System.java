package mol.word  ;

import com4j.*;

@IID("{00020935-0000-0000-C000-000000000046}")
public interface System extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String operatingSystem();

    @VTID(11)
    java.lang.String processorType();

    @VTID(12)
    java.lang.String version();

    @VTID(13)
    int freeDiskSpace();

    @VTID(14)
    mol.word.WdCountry country();

    @VTID(15)
    java.lang.String languageDesignation();

    @VTID(16)
    int horizontalResolution();

    @VTID(17)
    int verticalResolution();

    @VTID(18)
    java.lang.String profileString(
        java.lang.String section,
        java.lang.String key);

    @VTID(19)
    void profileString(
        java.lang.String section,
        java.lang.String key,
        java.lang.String prop);

    @VTID(20)
    java.lang.String privateProfileString(
        java.lang.String fileName,
        java.lang.String section,
        java.lang.String key);

    @VTID(21)
    void privateProfileString(
        java.lang.String fileName,
        java.lang.String section,
        java.lang.String key,
        java.lang.String prop);

    @VTID(22)
    boolean mathCoprocessorInstalled();

    @VTID(23)
    java.lang.String computerType();

    @VTID(24)
    java.lang.String macintoshName();

    @VTID(25)
    boolean quickDrawInstalled();

    @VTID(26)
    mol.word.WdCursorType cursor();

    @VTID(27)
    void cursor(
        mol.word.WdCursorType prop);

    @VTID(28)
    void msInfo();

    @VTID(29)
    void connect(
        java.lang.String path,
        java.lang.Object drive,
        java.lang.Object password);

    @VTID(30)
    mol.word.WdCountry countryRegion();

}
