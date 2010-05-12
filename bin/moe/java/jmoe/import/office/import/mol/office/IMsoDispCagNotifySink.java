package mol.office  ;

import com4j.*;

@IID("{000C0359-0000-0000-C000-000000000046}")
public interface IMsoDispCagNotifySink extends Com4jObject {
    @VTID(7)
    void insertClip(
        com4j.Com4jObject pClipMoniker,
        com4j.Com4jObject pItemMoniker);

    @VTID(8)
    void windowIsClosing();

}
