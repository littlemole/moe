package mol.mshtml  ;

import com4j.*;

@IID("{09B5EAB0-F997-11D1-93D4-0060B067B86E}")
public interface IEnumInputContext extends Com4jObject {
    @VTID(3)
    mol.mshtml.IEnumInputContext clone();

    @VTID(4)
    void next(
        int ulCount,
        Holder<Integer> rgInputContext,
        Holder<Integer> pcFetched);

    @VTID(5)
    void reset();

    @VTID(6)
    void skip(
        int ulCount);

}
