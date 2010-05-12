package mol.word  ;

import com4j.*;

@IID("{B5828B50-0E3D-448A-962D-A40702A5868D}")
public interface BuildingBlockTypes extends Com4jObject {
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
    @DefaultMethod
    mol.word.BuildingBlockType item(
        mol.word.WdBuildingBlockTypes index);

}
