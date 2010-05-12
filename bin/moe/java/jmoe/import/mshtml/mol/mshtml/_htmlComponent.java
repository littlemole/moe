package mol.mshtml  ;

import com4j.*;

public enum _htmlComponent implements ComEnum {
    htmlComponentClient(0),
    htmlComponentSbLeft(1),
    htmlComponentSbPageLeft(2),
    htmlComponentSbHThumb(3),
    htmlComponentSbPageRight(4),
    htmlComponentSbRight(5),
    htmlComponentSbUp(6),
    htmlComponentSbPageUp(7),
    htmlComponentSbVThumb(8),
    htmlComponentSbPageDown(9),
    htmlComponentSbDown(10),
    htmlComponentSbLeft2(11),
    htmlComponentSbPageLeft2(12),
    htmlComponentSbRight2(13),
    htmlComponentSbPageRight2(14),
    htmlComponentSbUp2(15),
    htmlComponentSbPageUp2(16),
    htmlComponentSbDown2(17),
    htmlComponentSbPageDown2(18),
    htmlComponentSbTop(19),
    htmlComponentSbBottom(20),
    htmlComponentOutside(21),
    htmlComponentGHTopLeft(22),
    htmlComponentGHLeft(23),
    htmlComponentGHTop(24),
    htmlComponentGHBottomLeft(25),
    htmlComponentGHTopRight(26),
    htmlComponentGHBottom(27),
    htmlComponentGHRight(28),
    htmlComponentGHBottomRight(29),
    htmlComponent_Max(2147483647),
    ;

    private final int value;
    _htmlComponent(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
