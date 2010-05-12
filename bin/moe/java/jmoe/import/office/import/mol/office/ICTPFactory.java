package mol.office  ;

import com4j.*;

@IID("{000C033D-0000-0000-C000-000000000046}")
public interface ICTPFactory extends Com4jObject {
    @VTID(7)
    mol.office._CustomTaskPane createCTP(
        java.lang.String ctpAxID,
        java.lang.String ctpTitle,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ctpParentWindow);

}
