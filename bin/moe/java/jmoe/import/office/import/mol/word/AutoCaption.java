package mol.word  ;

import com4j.*;

@IID("{0002097B-0000-0000-C000-000000000046}")
public interface AutoCaption extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String name();

    @VTID(11)
    boolean autoInsert();

    @VTID(12)
    void autoInsert(
        boolean prop);

    @VTID(13)
    int index();

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object captionLabel();

    @VTID(15)
    void captionLabel(
        java.lang.Object prop);

}
