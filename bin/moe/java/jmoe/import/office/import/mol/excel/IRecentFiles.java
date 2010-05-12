package mol.excel  ;

import com4j.*;

@IID("{00024406-0001-0000-C000-000000000046}")
public interface IRecentFiles extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int maximum();

    @VTID(11)
    void maximum(
        int rhs);

    @VTID(12)
    int count();

    @VTID(13)
    mol.excel.RecentFile item(
        int index);

    @VTID(14)
    @DefaultMethod
    mol.excel.RecentFile _Default(
        int index);

    @VTID(15)
    mol.excel.RecentFile add(
        java.lang.String name);

    @VTID(16)
    java.util.Iterator<Com4jObject> iterator();

}
