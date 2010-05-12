package mol.excel  ;

import com4j.*;

@IID("{00024465-0001-0000-C000-000000000046}")
public interface ISpellingOptions extends Com4jObject {
    @VTID(7)
    int dictLang();

    @VTID(8)
    void dictLang(
        int rhs);

    @VTID(9)
    java.lang.String userDict();

    @VTID(10)
    void userDict(
        java.lang.String rhs);

    @VTID(11)
    boolean ignoreCaps();

    @VTID(12)
    void ignoreCaps(
        boolean rhs);

    @VTID(13)
    boolean suggestMainOnly();

    @VTID(14)
    void suggestMainOnly(
        boolean rhs);

    @VTID(15)
    boolean ignoreMixedDigits();

    @VTID(16)
    void ignoreMixedDigits(
        boolean rhs);

    @VTID(17)
    boolean ignoreFileNames();

    @VTID(18)
    void ignoreFileNames(
        boolean rhs);

    @VTID(19)
    boolean germanPostReform();

    @VTID(20)
    void germanPostReform(
        boolean rhs);

    @VTID(21)
    boolean koreanCombineAux();

    @VTID(22)
    void koreanCombineAux(
        boolean rhs);

    @VTID(23)
    boolean koreanUseAutoChangeList();

    @VTID(24)
    void koreanUseAutoChangeList(
        boolean rhs);

    @VTID(25)
    boolean koreanProcessCompound();

    @VTID(26)
    void koreanProcessCompound(
        boolean rhs);

    @VTID(27)
    mol.excel.XlHebrewModes hebrewModes();

    @VTID(28)
    void hebrewModes(
        mol.excel.XlHebrewModes rhs);

    @VTID(29)
    mol.excel.XlArabicModes arabicModes();

    @VTID(30)
    void arabicModes(
        mol.excel.XlArabicModes rhs);

}
