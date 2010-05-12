package mol.office  ;

import com4j.*;

@IID("{55F88890-7708-11D1-ACEB-006008961DA5}")
public interface ICommandBarButtonEvents extends Com4jObject {
    @VTID(7)
    void click(
        mol.office._CommandBarButton ctrl,
        Holder<Boolean> cancelDefault);

}
