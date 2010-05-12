package mol.word  ;

import com4j.*;

@IID("{804CD967-F83B-432D-9446-C61A45CFEFF0}")
public interface ContentControls extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.ContentControl item(
        java.lang.Object index);

    @VTID(13)
    mol.word.ContentControl add(
        mol.word.WdContentControlType type,
        java.lang.Object range);

}
