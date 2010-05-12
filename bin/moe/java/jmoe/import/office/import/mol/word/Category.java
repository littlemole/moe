package mol.word  ;

import com4j.*;

@IID("{ECFBDB5E-ACD2-4530-AD79-4560B7FF055C}")
public interface Category extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int index();

    @VTID(11)
    java.lang.String name();

    @VTID(12)
    mol.word.BuildingBlocks buildingBlocks();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.word.BuildingBlocks.class})
    mol.word.BuildingBlock buildingBlocks(
        java.lang.Object index);

    @VTID(13)
    mol.word.BuildingBlockType type();

}
