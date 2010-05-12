package mol.office  ;

import com4j.*;

@IID("{000C030E-0000-0000-C000-000000000046}")
public interface _CommandBarButton extends mol.office.CommandBarControl {
    @VTID(83)
    boolean builtInFace();

    @VTID(84)
    void builtInFace(
        boolean pvarfBuiltIn);

    @VTID(85)
    void copyFace();

    @VTID(86)
    int faceId();

    @VTID(87)
    void faceId(
        int pid);

    @VTID(88)
    void pasteFace();

    @VTID(89)
    java.lang.String shortcutText();

    @VTID(90)
    void shortcutText(
        java.lang.String pbstrText);

    @VTID(91)
    mol.office.MsoButtonState state();

    @VTID(92)
    void state(
        mol.office.MsoButtonState pstate);

    @VTID(93)
    mol.office.MsoButtonStyle style();

    @VTID(94)
    void style(
        mol.office.MsoButtonStyle pstyle);

    @VTID(95)
    mol.office.MsoCommandBarButtonHyperlinkType hyperlinkType();

    @VTID(96)
    void hyperlinkType(
        mol.office.MsoCommandBarButtonHyperlinkType phlType);

        }
