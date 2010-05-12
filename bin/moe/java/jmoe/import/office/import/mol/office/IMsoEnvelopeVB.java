package mol.office  ;

import com4j.*;

@IID("{000672AC-0000-0000-C000-000000000046}")
public interface IMsoEnvelopeVB extends Com4jObject {
    @VTID(7)
    java.lang.String introduction();

    @VTID(8)
    void introduction(
        java.lang.String pbstrIntro);

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject commandBars();

}
