package mol.vba  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface _dispVBComponentsEvents extends Com4jObject {
    @DISPID(1)
    void itemAdded(
        mol.vba._VBComponent vbComponent);

    @DISPID(2)
    void itemRemoved(
        mol.vba._VBComponent vbComponent);

    @DISPID(3)
    void itemRenamed(
        mol.vba._VBComponent vbComponent,
        java.lang.String oldName);

    @DISPID(4)
    void itemSelected(
        mol.vba._VBComponent vbComponent);

    @DISPID(5)
    void itemActivated(
        mol.vba._VBComponent vbComponent);

    @DISPID(6)
    void itemReloaded(
        mol.vba._VBComponent vbComponent);

}
