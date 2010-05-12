package mol.word  ;

import com4j.*;

@IID("{E6AAEC05-E543-4085-BA92-9BF7D2474F51}")
public interface Research extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object query(
        java.lang.String serviceID,
        java.lang.String queryString,
        mol.word.WdLanguageID queryLanguage,
        boolean useSelection,
        boolean launchQuery);

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object setLanguagePair(
        mol.word.WdLanguageID languageFrom,
        mol.word.WdLanguageID languageTo);

    @VTID(12)
    boolean isResearchService(
        java.lang.String serviceID);

}
