package mol.word  ;

import com4j.*;

public enum WdBuiltInProperty implements ComEnum {
    wdPropertyTitle(1),
    wdPropertySubject(2),
    wdPropertyAuthor(3),
    wdPropertyKeywords(4),
    wdPropertyComments(5),
    wdPropertyTemplate(6),
    wdPropertyLastAuthor(7),
    wdPropertyRevision(8),
    wdPropertyAppName(9),
    wdPropertyTimeLastPrinted(10),
    wdPropertyTimeCreated(11),
    wdPropertyTimeLastSaved(12),
    wdPropertyVBATotalEdit(13),
    wdPropertyPages(14),
    wdPropertyWords(15),
    wdPropertyCharacters(16),
    wdPropertySecurity(17),
    wdPropertyCategory(18),
    wdPropertyFormat(19),
    wdPropertyManager(20),
    wdPropertyCompany(21),
    wdPropertyBytes(22),
    wdPropertyLines(23),
    wdPropertyParas(24),
    wdPropertySlides(25),
    wdPropertyNotes(26),
    wdPropertyHiddenSlides(27),
    wdPropertyMMClips(28),
    wdPropertyHyperlinkBase(29),
    wdPropertyCharsWSpaces(30),
    ;

    private final int value;
    WdBuiltInProperty(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
