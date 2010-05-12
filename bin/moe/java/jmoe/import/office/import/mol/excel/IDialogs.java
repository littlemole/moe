package mol.excel  ;

import com4j.*;

@IID("{00020879-0001-0000-C000-000000000046}")
public interface IDialogs extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.Dialog item(
        mol.excel.XlBuiltInDialog index);

    @VTID(12)
    @DefaultMethod
    mol.excel.Dialog _Default(
        mol.excel.XlBuiltInDialog index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

}
