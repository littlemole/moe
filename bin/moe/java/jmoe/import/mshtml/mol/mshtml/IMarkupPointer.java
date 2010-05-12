package mol.mshtml  ;

import com4j.*;

@IID("{3050F49F-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IMarkupPointer extends Com4jObject {
    @VTID(3)
    mol.mshtml.IHTMLDocument2 owningDoc();

    @VTID(4)
    mol.mshtml._POINTER_GRAVITY gravity();

    @VTID(5)
    void setGravity(
        mol.mshtml._POINTER_GRAVITY gravity);

    @VTID(6)
    int cling();

    @VTID(7)
    void setCling(
        int fCLing);

    @VTID(8)
    void unposition();

    @VTID(9)
    int isPositioned();

    @VTID(10)
    mol.mshtml.IMarkupContainer getContainer();

    @VTID(11)
    void moveAdjacentToElement(
        mol.mshtml.IHTMLElement pElement,
        mol.mshtml._ELEMENT_ADJACENCY eAdj);

    @VTID(12)
    void moveToPointer(
        mol.mshtml.IMarkupPointer pPointer);

    @VTID(13)
    void moveToContainer(
        mol.mshtml.IMarkupContainer pContainer,
        int fAtStart);

    @VTID(14)
    void left(
        int fMove,
        Holder<mol.mshtml._MARKUP_CONTEXT_TYPE> pContext,
        Holder<mol.mshtml.IHTMLElement> ppElement,
        Holder<Integer> pcch,
        Holder<Short> pchText);

    @VTID(15)
    void right(
        int fMove,
        Holder<mol.mshtml._MARKUP_CONTEXT_TYPE> pContext,
        Holder<mol.mshtml.IHTMLElement> ppElement,
        Holder<Integer> pcch,
        Holder<Short> pchText);

    @VTID(16)
    mol.mshtml.IHTMLElement currentScope();

    @VTID(17)
    int isLeftOf(
        mol.mshtml.IMarkupPointer pPointerThat);

    @VTID(18)
    int isLeftOfOrEqualTo(
        mol.mshtml.IMarkupPointer pPointerThat);

    @VTID(19)
    int isRightOf(
        mol.mshtml.IMarkupPointer pPointerThat);

    @VTID(20)
    int isRightOfOrEqualTo(
        mol.mshtml.IMarkupPointer pPointerThat);

    @VTID(21)
    int isEqualTo(
        mol.mshtml.IMarkupPointer pPointerThat);

    @VTID(22)
    void moveUnit(
        mol.mshtml._MOVEUNIT_ACTION muAction);

    @VTID(23)
    void findText(
        @MarshalAs(NativeType.Unicode) java.lang.String pchFindText,
        int dwFlags,
        mol.mshtml.IMarkupPointer pIEndMatch,
        mol.mshtml.IMarkupPointer pIEndSearch);

}
