package mol.word  ;

import com4j.*;

@IID("{D8779F01-4869-4403-B334-D60C5F9C9175}")
public interface OMathAutoCorrectEntry extends Com4jObject {
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
    java.lang.String value();

    @VTID(14)
    void value(
        java.lang.String prop);

    @VTID(15)
    void delete();

}
