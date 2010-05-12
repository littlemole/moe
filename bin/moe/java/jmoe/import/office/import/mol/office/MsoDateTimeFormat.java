package mol.office  ;

import com4j.*;

public enum MsoDateTimeFormat implements ComEnum {
    msoDateTimeFormatMixed(-2),
    msoDateTimeMdyy(1),
    msoDateTimeddddMMMMddyyyy(2),
    msoDateTimedMMMMyyyy(3),
    msoDateTimeMMMMdyyyy(4),
    msoDateTimedMMMyy(5),
    msoDateTimeMMMMyy(6),
    msoDateTimeMMyy(7),
    msoDateTimeMMddyyHmm(8),
    msoDateTimeMMddyyhmmAMPM(9),
    msoDateTimeHmm(10),
    msoDateTimeHmmss(11),
    msoDateTimehmmAMPM(12),
    msoDateTimehmmssAMPM(13),
    msoDateTimeFigureOut(14),
    ;

    private final int value;
    MsoDateTimeFormat(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
