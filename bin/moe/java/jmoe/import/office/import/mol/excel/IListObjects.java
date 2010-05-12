package mol.excel  ;

import com4j.*;

@IID("{00024470-0001-0000-C000-000000000046}")
public interface IListObjects extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.ListObject _Add(
        mol.excel.XlListObjectSourceType sourceType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object source,
        @MarshalAs(NativeType.VARIANT) java.lang.Object linkSource,
        mol.excel.XlYesNoGuess xlListObjectHasHeaders,
        @MarshalAs(NativeType.VARIANT) java.lang.Object destination);

    @VTID(11)
    @DefaultMethod
    mol.excel.ListObject _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(13)
    mol.excel.ListObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    int count();

    @VTID(15)
    mol.excel.ListObject add(
        mol.excel.XlListObjectSourceType sourceType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object source,
        @MarshalAs(NativeType.VARIANT) java.lang.Object linkSource,
        mol.excel.XlYesNoGuess xlListObjectHasHeaders,
        @MarshalAs(NativeType.VARIANT) java.lang.Object destination,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tableStyleName);

}
