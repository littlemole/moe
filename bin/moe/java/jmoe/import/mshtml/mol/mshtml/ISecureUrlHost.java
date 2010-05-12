package mol.mshtml  ;

import com4j.*;

@IID("{C81984C4-74C8-11D2-BAA9-00C04FC2040E}")
public interface ISecureUrlHost extends Com4jObject {
    @VTID(3)
    @ReturnValue(index=0)
    int validateSecureUrl(
        Holder<Short> pchUrlInQuestion,
        int dwFlags);

}
