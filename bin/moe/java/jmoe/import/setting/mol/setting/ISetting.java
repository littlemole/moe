package mol.setting  ;

import com4j.*;

/**
 * Setting
 */
@IID("{2DD18900-95F3-46A8-98B8-03F3843DE635}")
public interface ISetting extends Com4jObject,Iterable<Com4jObject> {
    /**
     * Get/Set Key Name
     */
    @VTID(7)
    void key(
        java.lang.String k);

    /**
     * Get/Set Key Name
     */
    @VTID(8)
    java.lang.String key();

    /**
     * Get/Set Value
     */
    @VTID(9)
    void value(
        java.lang.String v);

    /**
     * Get/Set Value
     */
    @VTID(10)
    java.lang.String value();

    /**
     * Parent Put
     */
    @VTID(11)
    void parent(
        mol.setting.ISetting s);

    /**
     * Parent Put
     */
    @VTID(12)
    mol.setting.ISetting parent();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.setting.ISetting.class})
    mol.setting.ISetting parent(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    /**
     * controls whether Children modification is allowedllowed
     */
    @VTID(13)
    void childrenAllowed(
        boolean vb);

    /**
     * controls whether Children modification is allowedllowed
     */
    @VTID(14)
    boolean childrenAllowed();

    /**
     * controls whether key is Readonly
     */
    @VTID(15)
    void keyReadOnly(
        boolean vb);

    /**
     * controls whether key is Readonly
     */
    @VTID(16)
    boolean keyReadOnly();

    /**
     * controls whether Value of Key is Readonly
     */
    @VTID(17)
    void valueReadOnly(
        boolean vb);

    /**
     * controls whether Value of Key is Readonly
     */
    @VTID(18)
    boolean valueReadOnly();

    /**
     * key or subkeys have changed
     */
    @VTID(19)
    boolean isDirty();

    /**
     * key or subkeys have changed
     */
    @VTID(20)
    void isDirty(
        boolean vb);

    /**
     * New Enum - enumeration for scripting languages
     */
    @VTID(21)
    java.util.Iterator<Com4jObject> iterator();

    /**
     * Item - get subkey at specific index
     */
    @VTID(22)
    @DefaultMethod
    mol.setting.ISetting item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    /**
     * returns number of subkeys for this key
     */
    @VTID(23)
    int count();

    /**
     * returns the root key
     */
    @VTID(24)
    mol.setting.ISetting root();

    @VTID(24)
    @ReturnValue(defaultPropertyThrough={mol.setting.ISetting.class})
    mol.setting.ISetting root(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    /**
     * returns Full Key Name
     */
    @VTID(25)
    java.lang.String keyName();

    /**
     * Add a new Setting as subkey
     */
    @VTID(26)
    void add(
        mol.setting.ISetting s);

    /**
     * Add a New subsetting Setting
     */
    @VTID(27)
    mol.setting.ISetting _new(
        java.lang.String k,
        java.lang.String v);

    /**
     * Remove this setting from parent
     */
    @VTID(28)
    void remove();

    /**
     * Remove subsetting at given index
     */
    @VTID(29)
    void removeItem(
        @MarshalAs(NativeType.VARIANT) java.lang.Object i);

    /**
     * Clear Children - remove all subsettings
     */
    @VTID(30)
    void clear();

    /**
     * load setting from file
     */
    @VTID(31)
    void load(
        java.lang.String fname);

    /**
     * save settings to file
     */
    @VTID(32)
    void save(
        java.lang.String fname);

    /**
     * Clone settings
     */
    @VTID(33)
    mol.setting.ISetting clone();

    @VTID(33)
    @ReturnValue(defaultPropertyThrough={mol.setting.ISetting.class})
    mol.setting.ISetting clone(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
