package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface SpellingOptions extends Com4jObject {
    @DISPID(2220)
    @PropGet
    int dictLang();

    @DISPID(2220)
    @PropPut
    void dictLang(
        int rhs);

    @DISPID(2221)
    @PropGet
    java.lang.String userDict();

    @DISPID(2221)
    @PropPut
    void userDict(
        java.lang.String rhs);

    @DISPID(2222)
    @PropGet
    boolean ignoreCaps();

    @DISPID(2222)
    @PropPut
    void ignoreCaps(
        boolean rhs);

    @DISPID(2223)
    @PropGet
    boolean suggestMainOnly();

    @DISPID(2223)
    @PropPut
    void suggestMainOnly(
        boolean rhs);

    @DISPID(2224)
    @PropGet
    boolean ignoreMixedDigits();

    @DISPID(2224)
    @PropPut
    void ignoreMixedDigits(
        boolean rhs);

    @DISPID(2225)
    @PropGet
    boolean ignoreFileNames();

    @DISPID(2225)
    @PropPut
    void ignoreFileNames(
        boolean rhs);

    @DISPID(2226)
    @PropGet
    boolean germanPostReform();

    @DISPID(2226)
    @PropPut
    void germanPostReform(
        boolean rhs);

    @DISPID(2227)
    @PropGet
    boolean koreanCombineAux();

    @DISPID(2227)
    @PropPut
    void koreanCombineAux(
        boolean rhs);

    @DISPID(2228)
    @PropGet
    boolean koreanUseAutoChangeList();

    @DISPID(2228)
    @PropPut
    void koreanUseAutoChangeList(
        boolean rhs);

    @DISPID(2229)
    @PropGet
    boolean koreanProcessCompound();

    @DISPID(2229)
    @PropPut
    void koreanProcessCompound(
        boolean rhs);

    @DISPID(2230)
    @PropGet
    mol.excel.XlHebrewModes hebrewModes();

    @DISPID(2230)
    @PropPut
    void hebrewModes(
        mol.excel.XlHebrewModes rhs);

    @DISPID(2231)
    @PropGet
    mol.excel.XlArabicModes arabicModes();

    @DISPID(2231)
    @PropPut
    void arabicModes(
        mol.excel.XlArabicModes rhs);

}
