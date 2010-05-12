package mol.mshtml  ;

import com4j.*;

@IID("{3050F844-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IEnumPrivacyRecords extends Com4jObject {
    @VTID(3)
    void reset();

    @VTID(4)
    int getSize();

    @VTID(5)
    int getPrivacyImpacted();

    @VTID(6)
    void next(
        Holder<java.lang.String> pbstrUrl,
        Holder<java.lang.String> pbstrPolicyRef,
        Holder<Integer> pdwReserved,
        Holder<Integer> pdwPrivacyFlags);

}
