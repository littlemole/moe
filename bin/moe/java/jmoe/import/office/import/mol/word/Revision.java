package mol.word  ;

import com4j.*;

@IID("{00020981-0000-0000-C000-000000000046}")
public interface Revision extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String author();

    @VTID(11)
    java.util.Date date();

    @VTID(12)
    mol.word.Range range();

    @VTID(13)
    mol.word.WdRevisionType type();

    @VTID(14)
    int index();

    @VTID(15)
    void accept();

    @VTID(16)
    void reject();

    @VTID(17)
    mol.word.Style style();

    @VTID(18)
    java.lang.String formatDescription();

    @VTID(19)
    mol.word.Range movedRange();

    @VTID(20)
    mol.word.Cells cells();

    @VTID(20)
    @ReturnValue(defaultPropertyThrough={mol.word.Cells.class})
    mol.word.Cell cells(
        int index);

}
