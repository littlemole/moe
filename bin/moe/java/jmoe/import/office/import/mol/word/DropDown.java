package mol.word  ;

import com4j.*;

@IID("{00020925-0000-0000-C000-000000000046}")
public interface DropDown extends Com4jObject {
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
    int _default();

    @VTID(12)
    void _default(
        int prop);

    @VTID(13)
    int value();

    @VTID(14)
    void value(
        int prop);

    @VTID(15)
    mol.word.ListEntries listEntries();

    @VTID(15)
    @ReturnValue(defaultPropertyThrough={mol.word.ListEntries.class})
    mol.word.ListEntry listEntries(
        java.lang.Object index);

}
