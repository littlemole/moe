package mol.mshtml  ;

import com4j.*;

@IID("{00000100-0000-0000-C000-000000000046}")
public interface IEnumUnknown extends Com4jObject {
    @VTID(3)
    void remoteNext(
        int celt,
        Holder<com4j.Com4jObject> rgelt,
        Holder<Integer> pceltFetched);

    @VTID(4)
    void skip(
        int celt);

    @VTID(5)
    void reset();

    @VTID(6)
    mol.mshtml.IEnumUnknown clone();

}
