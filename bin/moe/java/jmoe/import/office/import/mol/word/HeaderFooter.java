package mol.word  ;

import com4j.*;

@IID("{00020985-0000-0000-C000-000000000046}")
public interface HeaderFooter extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    mol.word.Range range();

    @VTID(11)
    mol.word.WdHeaderFooterIndex index();

    @VTID(12)
    boolean isHeader();

    @VTID(13)
    boolean exists();

    @VTID(14)
    void exists(
        boolean prop);

    @VTID(15)
    mol.word.PageNumbers pageNumbers();

    @VTID(15)
    @ReturnValue(defaultPropertyThrough={mol.word.PageNumbers.class})
    mol.word.PageNumber pageNumbers(
        int index);

    @VTID(16)
    boolean linkToPrevious();

    @VTID(17)
    void linkToPrevious(
        boolean prop);

    @VTID(18)
    mol.word.Shapes shapes();

    @VTID(18)
    @ReturnValue(defaultPropertyThrough={mol.word.Shapes.class})
    mol.word.Shape shapes(
        java.lang.Object index);

}
