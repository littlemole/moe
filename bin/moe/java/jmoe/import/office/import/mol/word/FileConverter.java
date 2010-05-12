package mol.word  ;

import com4j.*;

@IID("{00020999-0000-0000-C000-000000000046}")
public interface FileConverter extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String formatName();

    @VTID(11)
    java.lang.String className();

    @VTID(12)
    int saveFormat();

    @VTID(13)
    int openFormat();

    @VTID(14)
    boolean canSave();

    @VTID(15)
    boolean canOpen();

    @VTID(16)
    java.lang.String path();

    @VTID(17)
    java.lang.String name();

    @VTID(18)
    java.lang.String extensions();

}
