package mol.word  ;

import com4j.*;

@IID("{0002098F-0000-0000-C000-000000000046}")
public interface ListTemplate extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean outlineNumbered();

    @VTID(11)
    void outlineNumbered(
        boolean prop);

    @VTID(12)
    java.lang.String name();

    @VTID(13)
    void name(
        java.lang.String prop);

    @VTID(14)
    mol.word.ListLevels listLevels();

    @VTID(14)
    @ReturnValue(defaultPropertyThrough={mol.word.ListLevels.class})
    mol.word.ListLevel listLevels(
        int index);

    @VTID(15)
    mol.word.ListTemplate convert(
        java.lang.Object level);

}
