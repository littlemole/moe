package mol.word  ;

import com4j.*;

@IID("{00020919-0000-0000-C000-000000000046}")
public interface MailMergeDataField extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String value();

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    int index();

}
