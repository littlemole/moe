package mol.excel  ;

import com4j.*;

@IID("{0002442E-0001-0000-C000-000000000046}")
public interface IDummy extends Com4jObject {
    @VTID(7)
    void _ActiveSheetOrChart();

    @VTID(8)
    void rgb();

    @VTID(9)
    void chDir();

    @VTID(10)
    void doScript();

    @VTID(11)
    void directObject();

    @VTID(12)
    void refreshDocument();

    @VTID(13)
    mol.office.Signature addSignatureLine(
        @MarshalAs(NativeType.VARIANT) java.lang.Object sigProv);

    @VTID(14)
    mol.office.Signature addNonVisibleSignature(
        @MarshalAs(NativeType.VARIANT) java.lang.Object sigProv);

    @VTID(15)
    boolean showSignaturesPane();

    @VTID(16)
    void showSignaturesPane(
        boolean rhs);

    @VTID(17)
    void themeFontScheme();

    @VTID(18)
    void themeColorScheme();

    @VTID(19)
    void themeEffectScheme();

    @VTID(20)
    void load();

}
