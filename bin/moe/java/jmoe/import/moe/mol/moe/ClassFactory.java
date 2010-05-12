package mol.moe  ;

import com4j.*;

/**
 * Defines methods to create COM objects
 */
public abstract class ClassFactory {
    private ClassFactory() {} // instanciation is not allowed


    /**
     * Xmoe Application Object
     */
    public static mol.moe.IXmoe createXmoe() {
        return COM4J.createInstance( mol.moe.IXmoe.class, "{6282C9F1-F8B8-446B-9F98-1D4B7043BB9C}" );
    }
}
