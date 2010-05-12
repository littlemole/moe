package mol.word  ;

import com4j.*;

@IID("{0002092E-0000-0000-C000-000000000046}")
public interface Browser extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdBrowseTarget target();

    @VTID(11)
    void target(
        mol.word.WdBrowseTarget prop);

    @VTID(12)
    void next();

    @VTID(13)
    void previous();

}
