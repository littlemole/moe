package mol.office  ;

import com4j.*;

/**
 * Defines methods to create COM objects
 */
public abstract class ClassFactory {
    private ClassFactory() {} // instanciation is not allowed


    public static mol.office._CustomXMLSchemaCollection createCustomXMLSchemaCollection() {
        return COM4J.createInstance( mol.office._CustomXMLSchemaCollection.class, "{000CDB0D-0000-0000-C000-000000000046}" );
    }
}
