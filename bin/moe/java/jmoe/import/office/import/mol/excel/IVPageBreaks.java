package mol.excel  ;

import com4j.*;

@IID("{00024405-0001-0000-C000-000000000046}")
public interface IVPageBreaks extends Com4jObject,Iterable<Com4jObject> {
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
    mol.excel.VPageBreak item(
        int index);

    @VTID(12)
    @DefaultMethod
    mol.excel.VPageBreak _Default(
        int index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(14)
    mol.excel.VPageBreak add(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject before);

}
