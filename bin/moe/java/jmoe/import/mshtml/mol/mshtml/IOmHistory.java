package mol.mshtml  ;

import com4j.*;

@IID("{FECEAAA2-8405-11CF-8BA1-00AA00476DA6}")
public interface IOmHistory extends Com4jObject {
    @VTID(7)
    short length();

    @VTID(8)
    void back(
        java.lang.Object pvargdistance);

    @VTID(9)
    void forward(
        java.lang.Object pvargdistance);

    @VTID(10)
    void go(
        java.lang.Object pvargdistance);

}
