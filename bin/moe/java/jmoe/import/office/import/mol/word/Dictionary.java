package mol.word  ;

import com4j.*;

@IID("{000209AD-0000-0000-C000-000000000046}")
public interface Dictionary extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String name();

    @VTID(11)
    java.lang.String path();

    @VTID(12)
    mol.word.WdLanguageID languageID();

    @VTID(13)
    void languageID(
        mol.word.WdLanguageID prop);

    @VTID(14)
    boolean readOnly();

    @VTID(15)
    mol.word.WdDictionaryType type();

    @VTID(16)
    boolean languageSpecific();

    @VTID(17)
    void languageSpecific(
        boolean prop);

    @VTID(18)
    void delete();

}
