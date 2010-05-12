package mol.word  ;

import com4j.*;

@IID("{00020987-0000-0000-C000-000000000046}")
public interface PageNumber extends Com4jObject {
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
    mol.word.WdPageNumberAlignment alignment();

    @VTID(12)
    void alignment(
        mol.word.WdPageNumberAlignment prop);

    @VTID(13)
    void select();

    @VTID(14)
    void copy();

    @VTID(15)
    void cut();

    @VTID(16)
    void delete();

}
