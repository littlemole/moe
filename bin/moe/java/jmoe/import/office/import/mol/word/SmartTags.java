package mol.word  ;

import com4j.*;

@IID("{000209EE-0000-0000-C000-000000000046}")
public interface SmartTags extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word._Application application();

    @VTID(10)
    int creator();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    @DefaultMethod
    mol.word.SmartTag item(
        java.lang.Object index);

    @VTID(13)
    mol.word.SmartTag add(
        java.lang.String name,
        java.lang.Object range,
        java.lang.Object properties);

    @VTID(14)
    mol.word.SmartTags smartTagsByType(
        java.lang.String name);

}
