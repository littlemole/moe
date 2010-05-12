package mol.word  ;

import com4j.*;

public enum WdInformation implements ComEnum {
    wdActiveEndAdjustedPageNumber(1),
    wdActiveEndSectionNumber(2),
    wdActiveEndPageNumber(3),
    wdNumberOfPagesInDocument(4),
    wdHorizontalPositionRelativeToPage(5),
    wdVerticalPositionRelativeToPage(6),
    wdHorizontalPositionRelativeToTextBoundary(7),
    wdVerticalPositionRelativeToTextBoundary(8),
    wdFirstCharacterColumnNumber(9),
    wdFirstCharacterLineNumber(10),
    wdFrameIsSelected(11),
    wdWithInTable(12),
    wdStartOfRangeRowNumber(13),
    wdEndOfRangeRowNumber(14),
    wdMaximumNumberOfRows(15),
    wdStartOfRangeColumnNumber(16),
    wdEndOfRangeColumnNumber(17),
    wdMaximumNumberOfColumns(18),
    wdZoomPercentage(19),
    wdSelectionMode(20),
    wdCapsLock(21),
    wdNumLock(22),
    wdOverType(23),
    wdRevisionMarking(24),
    wdInFootnoteEndnotePane(25),
    wdInCommentPane(26),
    wdInHeaderFooter(28),
    wdAtEndOfRowMarker(31),
    wdReferenceOfType(32),
    wdHeaderFooterType(33),
    wdInMasterDocument(34),
    wdInFootnote(35),
    wdInEndnote(36),
    wdInWordMail(37),
    wdInClipboard(38),
    ;

    private final int value;
    WdInformation(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
