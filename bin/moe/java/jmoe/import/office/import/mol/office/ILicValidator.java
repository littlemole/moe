package mol.office  ;

import com4j.*;

@IID("{919AA22C-B9AD-11D3-8D59-0050048384E3}")
public interface ILicValidator extends Com4jObject {
    @VTID(7)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object products();

    @VTID(8)
    int selection();

    @VTID(9)
    void selection(
        int piSel);

}
