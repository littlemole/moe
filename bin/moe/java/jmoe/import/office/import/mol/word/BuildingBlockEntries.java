package mol.word  ;

import com4j.*;

@IID("{39709229-56A0-4E29-9112-B31DD067EBFD}")
public interface BuildingBlockEntries extends Com4jObject {
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
    mol.word.BuildingBlock item(
        java.lang.Object index);

    @VTID(12)
    mol.word.BuildingBlock add(
        java.lang.String name,
        mol.word.WdBuildingBlockTypes type,
        java.lang.String category,
        mol.word.Range range,
        java.lang.Object description,
        mol.word.WdDocPartInsertOptions insertOptions);

}
