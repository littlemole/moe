package mol.word  ;

import com4j.*;

@IID("{000209A6-0000-0000-C000-000000000046}")
public interface Zoom extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    int percentage();

    @VTID(11)
    @DefaultMethod
    void percentage(
        int prop);

    @VTID(12)
    mol.word.WdPageFit pageFit();

    @VTID(13)
    void pageFit(
        mol.word.WdPageFit prop);

    @VTID(14)
    int pageRows();

    @VTID(15)
    void pageRows(
        int prop);

    @VTID(16)
    int pageColumns();

    @VTID(17)
    void pageColumns(
        int prop);

}
