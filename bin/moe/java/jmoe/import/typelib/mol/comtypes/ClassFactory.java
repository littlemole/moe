package mol.comtypes  ;

import com4j.*;

/**
 * Defines methods to create COM objects
 */
public abstract class ClassFactory {
    private ClassFactory() {} // instanciation is not allowed


    /**
     * TypeLibToXml - Object for COM Type library to XML conversion
     */
    public static mol.comtypes.ITypeLibToXml createTypeLibToXml() {
        return COM4J.createInstance( mol.comtypes.ITypeLibToXml.class, "{9BFB3F1F-E302-4637-8495-7F7FDD29B57C}" );
    }
}
