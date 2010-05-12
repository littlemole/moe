package mol.word  ;

import com4j.*;

@IID("{E6AAEC05-E543-4085-BA92-9BF7D2474F5C}")
public interface TaskPanes extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.TaskPane item(
        mol.word.WdTaskPanes index);

}
