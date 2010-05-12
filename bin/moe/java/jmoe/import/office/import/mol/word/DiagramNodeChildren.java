package mol.word  ;

import com4j.*;

@IID("{000209EA-0000-0000-C000-000000000046}")
public interface DiagramNodeChildren extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    int count();

    @VTID(12)
    mol.word.DiagramNode firstChild();

    @VTID(13)
    mol.word.DiagramNode lastChild();

    @VTID(14)
    @DefaultMethod
    mol.word.DiagramNode item(
        java.lang.Object index);

    @VTID(15)
    mol.word.DiagramNode addNode(
        java.lang.Object index,
        mol.office.MsoDiagramNodeType nodeType);

    @VTID(16)
    void selectAll();

}
