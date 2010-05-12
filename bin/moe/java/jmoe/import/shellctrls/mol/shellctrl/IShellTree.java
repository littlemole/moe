package mol.shellctrl  ;

import com4j.*;

/**
 * ShellTree Interface
 */
@IID("{67282F00-10CA-4540-92B1-37DF10A3CD7B}")
public interface IShellTree extends Com4jObject {
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
     * Get/Set the current selection path
     */
    @VTID(9)
    void selection(
        java.lang.String fname);

    /**
     * Get/Set the current selection path
     */
    @VTID(10)
    java.lang.String selection();

    /**
     * returns true when Treeview has the focus
     */
    @VTID(11)
    boolean hasFocus();

    /**
     * Updates the Treeview
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
     * Add a network folder
     */
    @VTID(20)
    void addFolder(
        java.lang.String dname);

    /**
     * Remove a network folder
     */
    @VTID(21)
    void removeFolder(
        java.lang.String dname);

    /**
     * Create a new directory at current selection
     */
    @VTID(22)
    void createDir();

}
