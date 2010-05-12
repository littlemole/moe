package mol.word  ;

import com4j.*;

@IID("{00020927-0000-0000-C000-000000000046}")
public interface TextInput extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    boolean valid();

    @VTID(11)
    java.lang.String _default();

    @VTID(12)
    void _default(
        java.lang.String prop);

    @VTID(13)
    mol.word.WdTextFormFieldType type();

    @VTID(14)
    java.lang.String format();

    @VTID(15)
    int width();

    @VTID(16)
    void width(
        int prop);

    @VTID(17)
    void clear();

    @VTID(18)
    void editType(
        mol.word.WdTextFormFieldType type,
        java.lang.Object _default,
        java.lang.Object format,
        java.lang.Object enabled);

}
