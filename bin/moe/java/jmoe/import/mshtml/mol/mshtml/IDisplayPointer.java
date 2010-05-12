package mol.mshtml  ;

import com4j.*;

@IID("{3050F69E-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IDisplayPointer extends Com4jObject {
        @VTID(4)
        void moveUnit(
            mol.mshtml._DISPLAY_MOVEUNIT eMoveUnit,
            int lXPos);

        @VTID(5)
        void positionMarkupPointer(
            mol.mshtml.IMarkupPointer pMarkupPointer);

        @VTID(6)
        void moveToPointer(
            mol.mshtml.IDisplayPointer pDispPointer);

        @VTID(7)
        void setPointerGravity(
            mol.mshtml._POINTER_GRAVITY eGravity);

        @VTID(8)
        mol.mshtml._POINTER_GRAVITY getPointerGravity();

        @VTID(9)
        void setDisplayGravity(
            mol.mshtml._DISPLAY_GRAVITY eGravity);

        @VTID(10)
        mol.mshtml._DISPLAY_GRAVITY getDisplayGravity();

        @VTID(11)
        int isPositioned();

        @VTID(12)
        void unposition();

        @VTID(13)
        int isEqualTo(
            mol.mshtml.IDisplayPointer pDispPointer);

        @VTID(14)
        int isLeftOf(
            mol.mshtml.IDisplayPointer pDispPointer);

        @VTID(15)
        int isRightOf(
            mol.mshtml.IDisplayPointer pDispPointer);

        @VTID(16)
        int isAtBOL();

        @VTID(17)
        void moveToMarkupPointer(
            mol.mshtml.IMarkupPointer pPointer,
            mol.mshtml.IDisplayPointer pDispLineContext);

        @VTID(18)
        void scrollIntoView();

        @VTID(19)
        mol.mshtml.ILineInfo getLineInfo();

        @VTID(20)
        mol.mshtml.IHTMLElement getFlowElement();

        @VTID(21)
        int queryBreaks();

    }
