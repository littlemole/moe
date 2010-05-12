package mol.word  ;

import com4j.*;

@IID("{00020931-0000-0000-C000-000000000046}")
public interface LinkFormat extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean autoUpdate();

    @VTID(11)
    void autoUpdate(
        boolean prop);

    @VTID(12)
    java.lang.String sourceName();

    @VTID(13)
    java.lang.String sourcePath();

    @VTID(14)
    boolean locked();

    @VTID(15)
    void locked(
        boolean prop);

    @VTID(16)
    mol.word.WdLinkType type();

    @VTID(17)
    java.lang.String sourceFullName();

    @VTID(18)
    void sourceFullName(
        java.lang.String prop);

    @VTID(19)
    boolean savePictureWithDocument();

    @VTID(20)
    void savePictureWithDocument(
        boolean prop);

    @VTID(21)
    void breakLink();

    @VTID(22)
    void update();

}
