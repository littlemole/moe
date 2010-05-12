package mol.word  ;

import com4j.*;

@IID("{00020959-0000-0000-C000-000000000046}")
public interface Section extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    mol.word.Range range();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    mol.word.PageSetup pageSetup();

    @VTID(12)
    void pageSetup(
        mol.word.PageSetup prop);

    @VTID(13)
    mol.word.HeadersFooters headers();

    @VTID(13)
    @ReturnValue(defaultPropertyThrough={mol.word.HeadersFooters.class})
    mol.word.HeaderFooter headers(
        mol.word.WdHeaderFooterIndex index);

    @VTID(14)
    mol.word.HeadersFooters footers();

    @VTID(14)
    @ReturnValue(defaultPropertyThrough={mol.word.HeadersFooters.class})
    mol.word.HeaderFooter footers(
        mol.word.WdHeaderFooterIndex index);

    @VTID(15)
    boolean protectedForForms();

    @VTID(16)
    void protectedForForms(
        boolean prop);

    @VTID(17)
    int index();

    @VTID(18)
    mol.word.Borders borders();

    @VTID(18)
    @ReturnValue(defaultPropertyThrough={mol.word.Borders.class})
    mol.word.Border borders(
        mol.word.WdBorderType index);

    @VTID(19)
    void borders(
        mol.word.Borders prop);

}
