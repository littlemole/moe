package mol.vba  ;

import com4j.*;

@IID("{0002E167-0000-0000-C000-000000000046}")
public interface Events extends Com4jObject {
    @VTID(7)
    mol.vba._ReferencesEvents referencesEvents(
        mol.vba._VBProject vbProject);

    @VTID(8)
    mol.vba._CommandBarControlEvents commandBarEvents(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject commandBarControl);

}
