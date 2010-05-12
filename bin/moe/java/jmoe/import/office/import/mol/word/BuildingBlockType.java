package mol.word  ;

import com4j.*;

@IID("{817F99FA-CCC4-4971-8E9D-1238F735AAFF}")
public interface BuildingBlockType extends Com4jObject {
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
    mol.word.Categories categories();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.word.Categories.class})
    mol.word.Category categories(
        java.lang.Object index);

}
