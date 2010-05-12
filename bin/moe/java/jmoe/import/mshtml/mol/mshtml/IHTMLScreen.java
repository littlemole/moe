package mol.mshtml  ;

import com4j.*;

@IID("{3050F35C-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLScreen extends Com4jObject {
    @VTID(7)
    int colorDepth();

    @VTID(8)
    void bufferDepth(
        int p);

    @VTID(9)
    int bufferDepth();

    @VTID(10)
    int width();

    @VTID(11)
    int height();

    @VTID(12)
    void updateInterval(
        int p);

    @VTID(13)
    int updateInterval();

    @VTID(14)
    int availHeight();

    @VTID(15)
    int availWidth();

    @VTID(16)
    boolean fontSmoothingEnabled();

}
