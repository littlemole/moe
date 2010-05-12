package mol.mshtml  ;

import com4j.*;

@IID("{3050F682-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IMarkupServices2 extends mol.mshtml.IMarkupServices {
        @VTID(24)
        void validateElements(
            mol.mshtml.IMarkupPointer pPointerStart,
            mol.mshtml.IMarkupPointer pPointerFinish,
            mol.mshtml.IMarkupPointer pPointerTarget,
            mol.mshtml.IMarkupPointer pPointerStatus,
            Holder<mol.mshtml.IHTMLElement> ppElemFailBottom,
            Holder<mol.mshtml.IHTMLElement> ppElemFailTop);

        @VTID(25)
        void saveSegmentsToClipboard(
            mol.mshtml.ISegmentList pSegmentList,
            int dwFlags);

    }
