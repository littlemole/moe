package mol.excel  ;

import com4j.*;

@IID("{0002087B-0001-0000-C000-000000000046}")
public interface ISoundNote extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object delete();

    @VTID(11)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _import(
        java.lang.String filename);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object play();

    @VTID(13)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object record();

}
