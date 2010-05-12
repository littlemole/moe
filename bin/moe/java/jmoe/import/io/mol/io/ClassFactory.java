package mol.io  ;

import com4j.*;

/**
 * Defines methods to create COM objects
 */
public abstract class ClassFactory {
    private ClassFactory() {} // instanciation is not allowed


    public static mol.io.IPath createPath() {
        return COM4J.createInstance( mol.io.IPath.class, "{44DC1E37-CB3D-4328-B154-E50250F07A8F}" );
    }

    public static mol.io.IFile createfile() {
        return COM4J.createInstance( mol.io.IFile.class, "{C4E08E9A-0B46-4FD4-BB8D-588ABC27F52E}" );
    }
}
