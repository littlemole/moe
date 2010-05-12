package mol.word  ;

import com4j.*;

@IID("{0C6FA8CA-E65F-4FC7-AB8F-20729EECBB14}")
public interface ContentControlListEntry extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String text();

    @VTID(11)
    @DefaultMethod
    void text(
        java.lang.String prop);

    @VTID(12)
    java.lang.String value();

    @VTID(13)
    void value(
        java.lang.String prop);

    @VTID(14)
    int index();

    @VTID(15)
    void index(
        int prop);

    @VTID(16)
    void delete();

    @VTID(17)
    void moveUp();

    @VTID(18)
    void moveDown();

    @VTID(19)
    void select();

}
