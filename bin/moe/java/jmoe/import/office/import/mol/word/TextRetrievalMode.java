package mol.word  ;

import com4j.*;

@IID("{00020939-0000-0000-C000-000000000046}")
public interface TextRetrievalMode extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    mol.word.WdViewType viewType();

    @VTID(11)
    @DefaultMethod
    void viewType(
        mol.word.WdViewType prop);

    @VTID(12)
    mol.word.TextRetrievalMode duplicate();

    @VTID(13)
    boolean includeHiddenText();

    @VTID(14)
    void includeHiddenText(
        boolean prop);

    @VTID(15)
    boolean includeFieldCodes();

    @VTID(16)
    void includeFieldCodes(
        boolean prop);

}
