package mol.office  ;

import com4j.*;

@IID("{000C0322-0000-0000-C000-000000000046}")
public interface Assistant extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void move(
        int xLeft,
        int yTop);

    @VTID(11)
    void top(
        int pyTop);

    @VTID(12)
    int top();

    @VTID(13)
    void left(
        int pxLeft);

    @VTID(14)
    int left();

    @VTID(15)
    void help();

    @VTID(16)
    int startWizard(
        boolean on,
        java.lang.String callback,
        int privateX,
        @MarshalAs(NativeType.VARIANT) java.lang.Object animation,
        @MarshalAs(NativeType.VARIANT) java.lang.Object customTeaser,
        @MarshalAs(NativeType.VARIANT) java.lang.Object top,
        @MarshalAs(NativeType.VARIANT) java.lang.Object left,
        @MarshalAs(NativeType.VARIANT) java.lang.Object bottom,
        @MarshalAs(NativeType.VARIANT) java.lang.Object right);

    @VTID(17)
    void endWizard(
        int wizardID,
        boolean varfSuccess,
        @MarshalAs(NativeType.VARIANT) java.lang.Object animation);

    @VTID(18)
    void activateWizard(
        int wizardID,
        mol.office.MsoWizardActType act,
        @MarshalAs(NativeType.VARIANT) java.lang.Object animation);

    @VTID(19)
    void resetTips();

    @VTID(20)
    mol.office.Balloon newBalloon();

    @VTID(21)
    mol.office.MsoBalloonErrorType balloonError();

    @VTID(22)
    boolean visible();

    @VTID(23)
    void visible(
        boolean pvarfVisible);

    @VTID(24)
    mol.office.MsoAnimationType animation();

    @VTID(25)
    void animation(
        mol.office.MsoAnimationType pfca);

    @VTID(26)
    boolean reduced();

    @VTID(27)
    void reduced(
        boolean pvarfReduced);

    @VTID(28)
    void assistWithHelp(
        boolean pvarfAssistWithHelp);

    @VTID(29)
    boolean assistWithHelp();

    @VTID(30)
    void assistWithWizards(
        boolean pvarfAssistWithWizards);

    @VTID(31)
    boolean assistWithWizards();

    @VTID(32)
    void assistWithAlerts(
        boolean pvarfAssistWithAlerts);

    @VTID(33)
    boolean assistWithAlerts();

    @VTID(34)
    void moveWhenInTheWay(
        boolean pvarfMove);

    @VTID(35)
    boolean moveWhenInTheWay();

    @VTID(36)
    void sounds(
        boolean pvarfSounds);

    @VTID(37)
    boolean sounds();

    @VTID(38)
    void featureTips(
        boolean pvarfFeatures);

    @VTID(39)
    boolean featureTips();

    @VTID(40)
    void mouseTips(
        boolean pvarfMouse);

    @VTID(41)
    boolean mouseTips();

    @VTID(42)
    void keyboardShortcutTips(
        boolean pvarfKeyboardShortcuts);

    @VTID(43)
    boolean keyboardShortcutTips();

    @VTID(44)
    void highPriorityTips(
        boolean pvarfHighPriorityTips);

    @VTID(45)
    boolean highPriorityTips();

    @VTID(46)
    void tipOfDay(
        boolean pvarfTipOfDay);

    @VTID(47)
    boolean tipOfDay();

    @VTID(48)
    void guessHelp(
        boolean pvarfGuessHelp);

    @VTID(49)
    boolean guessHelp();

    @VTID(50)
    void searchWhenProgramming(
        boolean pvarfSearchInProgram);

    @VTID(51)
    boolean searchWhenProgramming();

    @VTID(52)
    @DefaultMethod
    java.lang.String item();

    @VTID(53)
    java.lang.String fileName();

    @VTID(54)
    void fileName(
        java.lang.String pbstr);

    @VTID(55)
    java.lang.String name();

    @VTID(56)
    boolean on();

    @VTID(57)
    void on(
        boolean pvarfOn);

    @VTID(58)
    int doAlert(
        java.lang.String bstrAlertTitle,
        java.lang.String bstrAlertText,
        mol.office.MsoAlertButtonType alb,
        mol.office.MsoAlertIconType alc,
        mol.office.MsoAlertDefaultType ald,
        mol.office.MsoAlertCancelType alq,
        boolean varfSysAlert);

}
