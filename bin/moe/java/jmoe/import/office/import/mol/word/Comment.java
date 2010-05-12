package mol.word  ;

import com4j.*;

@IID("{0002093D-0000-0000-C000-000000000046}")
public interface Comment extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.Range range();

    @VTID(11)
    mol.word.Range reference();

    @VTID(12)
    mol.word.Range scope();

    @VTID(13)
    int index();

    @VTID(14)
    java.lang.String author();

    @VTID(15)
    void author(
        java.lang.String prop);

    @VTID(16)
    java.lang.String initial();

    @VTID(17)
    void initial(
        java.lang.String prop);

    @VTID(18)
    boolean showTip();

    @VTID(19)
    void showTip(
        boolean prop);

    @VTID(20)
    void delete();

    @VTID(21)
    void edit();

    @VTID(22)
    java.util.Date date();

    @VTID(23)
    boolean isInk();

}
