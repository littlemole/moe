package mol.excel.events;

import com4j.*;

@IID("{0002441B-0000-0000-C000-000000000046}")
public abstract class RefreshEvents {
    @DISPID(1596)
    public void beforeRefresh(
        Holder<Boolean> cancel) {
            throw new UnsupportedOperationException();
    }

    @DISPID(1597)
    public void afterRefresh(
        boolean success) {
            throw new UnsupportedOperationException();
    }

}
