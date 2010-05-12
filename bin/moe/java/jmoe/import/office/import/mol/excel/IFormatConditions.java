package mol.excel  ;

import com4j.*;

@IID("{00024424-0001-0000-C000-000000000046}")
public interface IFormatConditions extends Com4jObject,Iterable<Com4jObject> {
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
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject add(
        mol.excel.XlFormatConditionType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object operator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object formula1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object formula2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object string,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textOperator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object dateOperator,
        @MarshalAs(NativeType.VARIANT) java.lang.Object scopeType);

    @VTID(13)
    @DefaultMethod
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(15)
    void delete();

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject addColorScale(
        int colorScaleType);

    @VTID(17)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject addDatabar();

    @VTID(18)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject addIconSetCondition();

    @VTID(19)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject addTop10();

    @VTID(20)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject addAboveAverage();

    @VTID(21)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject addUniqueValues();

}
