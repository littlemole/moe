package mol.word  ;

import com4j.*;

@IID("{5E9A888C-E5DC-4DCB-8308-3C91FB61E6F4}")
public interface SmartTagType extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String name();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    mol.word.SmartTagActions smartTagActions();

    @VTID(11)
    @ReturnValue(defaultPropertyThrough={mol.word.SmartTagActions.class})
    mol.word.SmartTagAction smartTagActions(
        java.lang.Object index);

    @VTID(12)
    mol.word.SmartTagRecognizers smartTagRecognizers();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.word.SmartTagRecognizers.class})
    mol.word.SmartTagRecognizer smartTagRecognizers(
        java.lang.Object index);

    @VTID(13)
    java.lang.String friendlyName();

}
