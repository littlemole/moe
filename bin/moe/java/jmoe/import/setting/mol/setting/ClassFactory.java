package mol.setting  ;

import com4j.*;

/**
 * Defines methods to create COM objects
 */
public abstract class ClassFactory {
    private ClassFactory() {} // instanciation is not allowed


    public static mol.setting.ISetting createSetting() {
        return COM4J.createInstance( mol.setting.ISetting.class, "{AE500EE9-731F-47A8-8D11-634EF422A396}" );
    }

    /**
     * ISetting Property Page
     */
    public static Com4jObject createSettingProperties() {
        return COM4J.createInstance( Com4jObject.class, "{5754B136-D3FB-4232-B94A-92B44BE066E9}" );
    }
}
