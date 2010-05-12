package mol.word  ;

import com4j.*;

@IID("{0002096D-0000-0000-C000-000000000046}")
public interface Language extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdLanguageID id();

    @VTID(11)
    @DefaultMethod
    java.lang.String nameLocal();

    @VTID(12)
    java.lang.String name();

    @VTID(13)
    mol.word.Dictionary activeGrammarDictionary();

    @VTID(14)
    mol.word.Dictionary activeHyphenationDictionary();

    @VTID(15)
    mol.word.Dictionary activeSpellingDictionary();

    @VTID(16)
    mol.word.Dictionary activeThesaurusDictionary();

    @VTID(17)
    java.lang.String defaultWritingStyle();

    @VTID(18)
    void defaultWritingStyle(
        java.lang.String prop);

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object writingStyleList();

    @VTID(20)
    mol.word.WdDictionaryType spellingDictionaryType();

    @VTID(21)
    void spellingDictionaryType(
        mol.word.WdDictionaryType prop);

}
