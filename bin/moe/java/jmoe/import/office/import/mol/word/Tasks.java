package mol.word  ;

import com4j.*;

@IID("{00020983-0000-0000-C000-000000000046}")
public interface Tasks extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(11)
    int count();

    @VTID(12)
    @DefaultMethod
    mol.word.Task item(
        java.lang.Object index);

    @VTID(13)
    boolean exists(
        java.lang.String name);

    @VTID(14)
    void exitWindows();

}