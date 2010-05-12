package mol.word  ;

import com4j.*;

@IID("{00020936-0000-0000-C000-000000000046}")
public interface AutoTextEntry extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int index();

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    void name(
        java.lang.String prop);

    @VTID(13)
    java.lang.String styleName();

    @VTID(14)
    @DefaultMethod
    java.lang.String value();

    @VTID(15)
    @DefaultMethod
    void value(
        java.lang.String prop);

    @VTID(16)
    void delete();

    @VTID(17)
    mol.word.Range insert(
        mol.word.Range where,
        java.lang.Object richText);

}
