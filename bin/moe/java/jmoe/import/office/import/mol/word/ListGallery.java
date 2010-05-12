package mol.word  ;

import com4j.*;

@IID("{00020994-0000-0000-C000-000000000046}")
public interface ListGallery extends Com4jObject {
    @VTID(7)
    mol.word.ListTemplates listTemplates();

    @VTID(7)
    @ReturnValue(defaultPropertyThrough={mol.word.ListTemplates.class})
    mol.word.ListTemplate listTemplates(
        java.lang.Object index);

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    boolean modified(
        int index);

    @VTID(12)
    void reset(
        int index);

}
