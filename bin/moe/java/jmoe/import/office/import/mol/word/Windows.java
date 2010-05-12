package mol.word  ;

import com4j.*;

@IID("{00020961-0000-0000-C000-000000000046}")
public interface Windows extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word._Application application();

    @VTID(10)
    int creator();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    @DefaultMethod
    mol.word.Window item(
        java.lang.Object index);

    @VTID(13)
    mol.word.Window add(
        java.lang.Object window);

    @VTID(14)
    void arrange(
        java.lang.Object arrangeStyle);

    @VTID(15)
    boolean compareSideBySideWith(
        java.lang.Object document);

    @VTID(16)
    boolean breakSideBySide();

    @VTID(17)
    void resetPositionsSideBySide();

    @VTID(18)
    boolean syncScrollingSideBySide();

    @VTID(19)
    void syncScrollingSideBySide(
        boolean prop);

}
