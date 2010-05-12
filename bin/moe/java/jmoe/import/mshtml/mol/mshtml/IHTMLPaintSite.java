package mol.mshtml  ;

import com4j.*;

@IID("{3050F6A7-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLPaintSite extends Com4jObject {
    @VTID(3)
    void invalidatePainterInfo();

        @VTID(5)
        void invalidateRegion(
            int rgnInvalid);

        @VTID(9)
        int getHitTestCookie();

    }
