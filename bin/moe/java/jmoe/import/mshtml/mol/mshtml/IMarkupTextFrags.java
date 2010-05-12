package mol.mshtml  ;

import com4j.*;

@IID("{3050F5FA-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IMarkupTextFrags extends Com4jObject {
    @VTID(3)
    int getTextFragCount();

    @VTID(4)
    @ReturnValue(index=1)
    java.lang.String getTextFrag(
        int iFrag,
        mol.mshtml.IMarkupPointer pPointerFrag);

    @VTID(5)
    void removeTextFrag(
        int iFrag);

    @VTID(6)
    void insertTextFrag(
        int iFrag,
        java.lang.String bstrInsert,
        mol.mshtml.IMarkupPointer pPointerInsert);

    @VTID(7)
    void findTextFragFromMarkupPointer(
        mol.mshtml.IMarkupPointer pPointerFind,
        Holder<Integer> piFrag,
        Holder<Integer> pfFragFound);

}
