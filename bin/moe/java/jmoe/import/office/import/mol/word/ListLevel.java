package mol.word  ;

import com4j.*;

@IID("{0002098D-0000-0000-C000-000000000046}")
public interface ListLevel extends Com4jObject {
    @VTID(7)
    int index();

    @VTID(8)
    java.lang.String numberFormat();

    @VTID(9)
    void numberFormat(
        java.lang.String prop);

    @VTID(10)
    mol.word.WdTrailingCharacter trailingCharacter();

    @VTID(11)
    void trailingCharacter(
        mol.word.WdTrailingCharacter prop);

    @VTID(12)
    mol.word.WdListNumberStyle numberStyle();

    @VTID(13)
    void numberStyle(
        mol.word.WdListNumberStyle prop);

    @VTID(14)
    float numberPosition();

    @VTID(15)
    void numberPosition(
        float prop);

    @VTID(16)
    mol.word.WdListLevelAlignment alignment();

    @VTID(17)
    void alignment(
        mol.word.WdListLevelAlignment prop);

    @VTID(18)
    float textPosition();

    @VTID(19)
    void textPosition(
        float prop);

    @VTID(20)
    float tabPosition();

    @VTID(21)
    void tabPosition(
        float prop);

    @VTID(22)
    boolean resetOnHigherOld();

    @VTID(23)
    void resetOnHigherOld(
        boolean prop);

    @VTID(24)
    int startAt();

    @VTID(25)
    void startAt(
        int prop);

    @VTID(26)
    java.lang.String linkedStyle();

    @VTID(27)
    void linkedStyle(
        java.lang.String prop);

    @VTID(28)
    mol.word._Font font();

    @VTID(29)
    void font(
        mol.word._Font prop);

    @VTID(30)
    mol.word._Application application();

    @VTID(31)
    int creator();

    @VTID(32)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(33)
    int resetOnHigher();

    @VTID(34)
    void resetOnHigher(
        int prop);

    @VTID(35)
    mol.word.InlineShape pictureBullet();

    @VTID(36)
    @DefaultMethod
    mol.word.InlineShape applyPictureBullet(
        java.lang.String fileName);

}
