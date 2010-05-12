package mol.excel  ;

import com4j.*;

@IID("{00020860-0001-0000-C000-000000000046}")
public interface IAreas extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    mol.excel.Range item(
        int index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(13)
    @DefaultMethod
    mol.excel.Range _Default(
        int index);

}
