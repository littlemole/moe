package mol.word  ;

import com4j.*;

@IID("{00020973-0000-0000-C000-000000000046}")
public interface TextColumns extends Com4jObject,Iterable<Com4jObject> {
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
    int evenlySpaced();

    @VTID(13)
    void evenlySpaced(
        int prop);

    @VTID(14)
    int lineBetween();

    @VTID(15)
    void lineBetween(
        int prop);

    @VTID(16)
    float width();

    @VTID(17)
    void width(
        float prop);

    @VTID(18)
    float spacing();

    @VTID(19)
    void spacing(
        float prop);

    @VTID(20)
    @DefaultMethod
    mol.word.TextColumn item(
        int index);

    @VTID(21)
    mol.word.TextColumn add(
        java.lang.Object width,
        java.lang.Object spacing,
        java.lang.Object evenlySpaced);

    @VTID(22)
    void setCount(
        int numColumns);

    @VTID(23)
    mol.word.WdFlowDirection flowDirection();

    @VTID(24)
    void flowDirection(
        mol.word.WdFlowDirection prop);

}
