package mol.word  ;

import com4j.*;

@IID("{000209B6-0000-0000-C000-000000000046}")
public interface GroupShapes extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    @DefaultMethod
    mol.word.Shape item(
        java.lang.Object index);

    @VTID(13)
    mol.word.ShapeRange range(
        java.lang.Object index);

}
