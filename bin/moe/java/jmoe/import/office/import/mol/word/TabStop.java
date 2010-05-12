package mol.word  ;

import com4j.*;

@IID("{00020954-0000-0000-C000-000000000046}")
public interface TabStop extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.word.WdTabAlignment alignment();

    @VTID(11)
    void alignment(
        mol.word.WdTabAlignment prop);

    @VTID(12)
    mol.word.WdTabLeader leader();

    @VTID(13)
    void leader(
        mol.word.WdTabLeader prop);

    @VTID(14)
    float position();

    @VTID(15)
    void position(
        float prop);

    @VTID(16)
    boolean customTab();

    @VTID(17)
    mol.word.TabStop next();

    @VTID(18)
    mol.word.TabStop previous();

    @VTID(19)
    void clear();

}
