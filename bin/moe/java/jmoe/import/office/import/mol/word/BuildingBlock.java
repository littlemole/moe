package mol.word  ;

import com4j.*;

@IID("{BFD3FC23-F763-4FF8-826E-1AFBF598A4E7}")
public interface BuildingBlock extends Com4jObject {
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
    java.lang.String name();

    @VTID(12)
    void name(
        java.lang.String prop);

    @VTID(13)
    mol.word.BuildingBlockType type();

    @VTID(14)
    java.lang.String description();

    @VTID(15)
    void description(
        java.lang.String prop);

    @VTID(16)
    java.lang.String id();

    @VTID(17)
    mol.word.Category category();

    @VTID(18)
    @DefaultMethod
    java.lang.String value();

    @VTID(19)
    @DefaultMethod
    void value(
        java.lang.String prop);

    @VTID(20)
    int insertOptions();

    @VTID(21)
    void insertOptions(
        int prop);

    @VTID(22)
    void delete();

    @VTID(23)
    mol.word.Range insert(
        mol.word.Range where,
        java.lang.Object richText);

}
