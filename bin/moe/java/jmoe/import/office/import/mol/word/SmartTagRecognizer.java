package mol.word  ;

import com4j.*;

@IID("{15EBE471-0182-4CCE-98D0-B6614D1C32A1}")
public interface SmartTagRecognizer extends Com4jObject {
    @VTID(7)
    java.lang.String fullName();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    boolean enabled();

    @VTID(12)
    void enabled(
        boolean prop);

    @VTID(13)
    @DefaultMethod
    java.lang.String progID();

    @VTID(14)
    java.lang.String caption();

}
