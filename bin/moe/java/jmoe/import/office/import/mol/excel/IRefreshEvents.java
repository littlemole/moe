package mol.excel  ;

import com4j.*;

@IID("{0002441B-0001-0000-C000-000000000046}")
public interface IRefreshEvents extends Com4jObject {
    @VTID(7)
    void beforeRefresh(
        Holder<Boolean> cancel);

    @VTID(8)
    void afterRefresh(
        boolean success);

}
