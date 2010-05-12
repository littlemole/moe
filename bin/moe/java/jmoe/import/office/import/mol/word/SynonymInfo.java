package mol.word  ;

import com4j.*;

@IID("{0002099B-0000-0000-C000-000000000046}")
public interface SynonymInfo extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String word();

    @VTID(11)
    boolean found();

    @VTID(12)
    int meaningCount();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object meaningList();

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object partOfSpeechList();

    @VTID(15)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object synonymList(
        java.lang.Object meaning);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object antonymList();

    @VTID(17)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object relatedExpressionList();

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object relatedWordList();

}
