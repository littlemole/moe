package mol.word  ;

import com4j.*;

@IID("{5C04BD93-2F3F-4668-918D-9738EC901039}")
public interface OMathRecognizedFunction extends Com4jObject {
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
    void delete();

}
