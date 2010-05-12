package mol.word  ;

import com4j.*;

@IID("{12DCDC9A-5418-48A3-BBE6-EB57BAE275E8}")
public interface Reviewers extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    int count();

    @VTID(12)
    @DefaultMethod
    mol.word.Reviewer item(
        java.lang.Object index);

}
