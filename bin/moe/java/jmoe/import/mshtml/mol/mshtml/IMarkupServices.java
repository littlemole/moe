package mol.mshtml  ;

import com4j.*;

@IID("{3050F4A0-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IMarkupServices extends Com4jObject {
    @VTID(3)
    mol.mshtml.IMarkupPointer createMarkupPointer();

    @VTID(4)
    mol.mshtml.IMarkupContainer createMarkupContainer();

    @VTID(5)
    mol.mshtml.IHTMLElement createElement(
        mol.mshtml._ELEMENT_TAG_ID tagID,
        Holder<Short> pchAttributes);

    @VTID(6)
    mol.mshtml.IHTMLElement cloneElement(
        mol.mshtml.IHTMLElement pElemCloneThis);

    @VTID(7)
    void insertElement(
        mol.mshtml.IHTMLElement pElementInsert,
        mol.mshtml.IMarkupPointer pPointerStart,
        mol.mshtml.IMarkupPointer pPointerFinish);

    @VTID(8)
    void removeElement(
        mol.mshtml.IHTMLElement pElementRemove);

    @VTID(9)
    void remove(
        mol.mshtml.IMarkupPointer pPointerStart,
        mol.mshtml.IMarkupPointer pPointerFinish);

    @VTID(10)
    void copy(
        mol.mshtml.IMarkupPointer pPointerSourceStart,
        mol.mshtml.IMarkupPointer pPointerSourceFinish,
        mol.mshtml.IMarkupPointer pPointerTarget);

    @VTID(11)
    void move(
        mol.mshtml.IMarkupPointer pPointerSourceStart,
        mol.mshtml.IMarkupPointer pPointerSourceFinish,
        mol.mshtml.IMarkupPointer pPointerTarget);

    @VTID(12)
    void insertText(
        Holder<Short> pchText,
        int cch,
        mol.mshtml.IMarkupPointer pPointerTarget);

    @VTID(13)
    @ReturnValue(index=2)
    mol.mshtml.IMarkupContainer parseString(
        Holder<Short> pchHTML,
        int dwFlags,
        mol.mshtml.IMarkupPointer ppPointerStart,
        mol.mshtml.IMarkupPointer ppPointerFinish);

        @VTID(15)
        int isScopedElement(
            mol.mshtml.IHTMLElement pElement);

        @VTID(16)
        mol.mshtml._ELEMENT_TAG_ID getElementTagId(
            mol.mshtml.IHTMLElement pElement);

        @VTID(17)
        mol.mshtml._ELEMENT_TAG_ID getTagIDForName(
            java.lang.String bstrName);

        @VTID(18)
        java.lang.String getNameForTagID(
            mol.mshtml._ELEMENT_TAG_ID tagID);

        @VTID(19)
        void movePointersToRange(
            mol.mshtml.IHTMLTxtRange pIRange,
            mol.mshtml.IMarkupPointer pPointerStart,
            mol.mshtml.IMarkupPointer pPointerFinish);

        @VTID(20)
        void moveRangeToPointers(
            mol.mshtml.IMarkupPointer pPointerStart,
            mol.mshtml.IMarkupPointer pPointerFinish,
            mol.mshtml.IHTMLTxtRange pIRange);

        @VTID(21)
        void beginUndoUnit(
            Holder<Short> pchTitle);

        @VTID(22)
        void endUndoUnit();

    }
