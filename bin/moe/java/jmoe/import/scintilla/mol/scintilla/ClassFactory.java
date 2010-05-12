package mol.scintilla  ;

import com4j.*;

/**
 * Defines methods to create COM objects
 */
public abstract class ClassFactory {
    private ClassFactory() {} // instanciation is not allowed


    public static mol.scintilla.IScintillAx createScintillAx() {
        return COM4J.createInstance( mol.scintilla.IScintillAx.class, "{9B5488B0-33FB-44DF-8D58-672A1C1E08C1}" );
    }

    /**
     * IScintillAx Property Page
     */
    public static Com4jObject createScintillAxProperties() {
        return COM4J.createInstance( Com4jObject.class, "{C16CD143-5126-414A-AFDE-406F31E95D13}" );
    }
}
