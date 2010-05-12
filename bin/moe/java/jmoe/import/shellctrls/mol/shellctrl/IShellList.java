package mol.shellctrl  ;

import com4j.*;

/**
 * ShellList Interface
 */
@IID("{9C93223B-E503-415A-811A-B817D7B1BC43}")
public interface IShellList extends Com4jObject {
    /**
     * Get/Set Display of files
     */
    @VTID(7)
    void displayFiles(
        boolean vb);

    /**
     * Get/Set Display of files
     */
    @VTID(8)
    boolean displayFiles();

    /**
     * Get/Set current selection
     */
    @VTID(9)
    void selection(
        @MarshalAs(NativeType.VARIANT) java.lang.Object fname);

    /**
     * Get/Set current selection
     */
    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object selection();

    /**
     * returns true when Listview has the focus
     */
    @VTID(11)
    boolean hasFocus();

    /**
     * Update Listview
     */
    @VTID(12)
    void update();

    /**
     * Cut current selection
     */
    @VTID(13)
    void cut();

    /**
     * Copy current selection
     */
    @VTID(14)
    void copy();

    /**
     * Paste current selection
     */
    @VTID(15)
    void paste();

    /**
     * Rename current selection
     */
    @VTID(16)
    void rename();

    /**
     * Delete current selection
     */
    @VTID(17)
    void delete();

    /**
     * Properties for current selection
     */
    @VTID(18)
    void properties();

    /**
     * ShellExecute current selection
     */
    @VTID(19)
    void execute();

    /**
     * Create new directory
     */
    @VTID(20)
    void createDir();

    /**
     * Up to parent directory
     */
    @VTID(21)
    void upDir();

}
