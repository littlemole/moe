package mol.wsh  ;

import com4j.*;

/**
 * Defines methods to create COM objects
 */
public abstract class ClassFactory {
    private ClassFactory() {} // instanciation is not allowed


    public static mol.wsh.IFileSystem3 createFileSystemObject() {
        return COM4J.createInstance( mol.wsh.IFileSystem3.class, "{0D43FE01-F093-11CF-8940-00A0C9054228}" );
    }

    /**
     * Shell Object
     */
    public static mol.wsh.IWshShell3 createWshShell() {
        return COM4J.createInstance( mol.wsh.IWshShell3.class, "{72C24DD5-D70A-438B-8A42-98424B88AFB8}" );
    }

    /**
     * Shell Object
     */
    public static mol.wsh.IWshShell3 createIWshShell_Class() {
        return COM4J.createInstance( mol.wsh.IWshShell3.class, "{F935DC22-1CF0-11D0-ADB9-00C04FD58A0B}" );
    }

    /**
     * Network Object
     */
    public static mol.wsh.IWshNetwork2 createWshNetwork() {
        return COM4J.createInstance( mol.wsh.IWshNetwork2.class, "{093FF999-1EA0-4079-9525-9614C3504B74}" );
    }

    /**
     * Network Object
     */
    public static mol.wsh.IWshNetwork2 createIWshNetwork_Class() {
        return COM4J.createInstance( mol.wsh.IWshNetwork2.class, "{F935DC26-1CF0-11D0-ADB9-00C04FD58A0B}" );
    }
}
