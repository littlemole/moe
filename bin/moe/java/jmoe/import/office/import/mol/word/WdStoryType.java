package mol.word  ;

import com4j.*;

public enum WdStoryType implements ComEnum {
    wdMainTextStory(1),
    wdFootnotesStory(2),
    wdEndnotesStory(3),
    wdCommentsStory(4),
    wdTextFrameStory(5),
    wdEvenPagesHeaderStory(6),
    wdPrimaryHeaderStory(7),
    wdEvenPagesFooterStory(8),
    wdPrimaryFooterStory(9),
    wdFirstPageHeaderStory(10),
    wdFirstPageFooterStory(11),
    wdFootnoteSeparatorStory(12),
    wdFootnoteContinuationSeparatorStory(13),
    wdFootnoteContinuationNoticeStory(14),
    wdEndnoteSeparatorStory(15),
    wdEndnoteContinuationSeparatorStory(16),
    wdEndnoteContinuationNoticeStory(17),
    ;

    private final int value;
    WdStoryType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
