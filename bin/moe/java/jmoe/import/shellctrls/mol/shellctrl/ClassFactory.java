package mol.shellctrl  ;

import com4j.*;

/**
 * Defines methods to create COM objects
 */
public abstract class ClassFactory {
    private ClassFactory() {} // instanciation is not allowed


    public static mol.shellctrl.IShellTree createShellTree() {
        return COM4J.createInstance( mol.shellctrl.IShellTree.class, "{22C25563-E185-4753-8299-1998CD73D389}" );
    }

    public static mol.shellctrl.IShellList createShellList() {
        return COM4J.createInstance( mol.shellctrl.IShellList.class, "{8E6A9C86-2FA6-4D02-B9BE-72326A7F6C9D}" );
    }

    public static mol.shellctrl.IColorPicker createColorDialog() {
        return COM4J.createInstance( mol.shellctrl.IColorPicker.class, "{ADF80C5A-78DE-4317-BF08-4CE3176D3422}" );
    }

    public static mol.shellctrl.IHexCtrl createHexCtrl() {
        return COM4J.createInstance( mol.shellctrl.IHexCtrl.class, "{E83EC0F6-6AF3-44F8-901E-AF01F84FE6D0}" );
    }
}
