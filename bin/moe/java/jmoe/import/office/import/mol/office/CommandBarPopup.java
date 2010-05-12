package mol.office  ;

import com4j.*;

@IID("{000C030A-0000-0000-C000-000000000046}")
public interface CommandBarPopup extends mol.office.CommandBarControl {
    @VTID(83)
    mol.office.CommandBar commandBar();

    @VTID(84)
    mol.office.CommandBarControls controls();

    @VTID(84)
    @ReturnValue(defaultPropertyThrough={mol.office.CommandBarControls.class})
    mol.office.CommandBarControl controls(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(85)
    mol.office.MsoOLEMenuGroup oleMenuGroup();

    @VTID(86)
    void oleMenuGroup(
        mol.office.MsoOLEMenuGroup pomg);

}
