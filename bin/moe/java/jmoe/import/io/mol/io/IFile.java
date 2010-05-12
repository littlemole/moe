package mol.io  ;

import com4j.*;

/**
 * IFile - simple Scripting File Access interface
 */
@IID("{5AF00596-158A-4DDD-BC20-83BC8D5E432F}")
public interface IFile extends Com4jObject {
    /**
     * Get Filename
     */
    @VTID(7)
    java.lang.String filename();

    /**
     * Set EOL mode
     */
    @VTID(8)
    void eoL(
        int t);

    /**
     * Set EOL mode
     */
    @VTID(9)
    int eoL();

    /**
     * Set Encoding
     */
    @VTID(10)
    void encoding(
        int cp);

    /**
     * Set Encoding
     */
    @VTID(11)
    int encoding();

    /**
     * Set BOM Usage
     */
    @VTID(12)
    void useBOM(
        boolean vb);

    /**
     * Set BOM Usage
     */
    @VTID(13)
    boolean useBOM();

    /**
     * Get End of File - indicates whether end of file reached
     */
    @VTID(14)
    boolean eoF();

    /**
     * Get File Size
     */
    @VTID(15)
    int size();

    /**
     * Open File
     */
    @VTID(16)
    boolean open(
        java.lang.String file);

    /**
     * Open File Read Only
     */
    @VTID(17)
    boolean openReadOnly(
        java.lang.String file);

    /**
     * Open File for Append
     */
    @VTID(18)
    boolean openAppend(
        java.lang.String file);

    /**
     * Close File
     */
    @VTID(19)
    void close();

    /**
     * Read up to a specific count from file
     */
    @VTID(20)
    java.lang.String read(
        int cnt);

    /**
     * Read complete File as one Text String
     */
    @VTID(21)
    java.lang.String readText();

    /**
     * Seek a specific file position before reading/writing
     */
    @VTID(22)
    void seek(
        int pos);

    /**
     * Write a string to a file
     */
    @VTID(23)
    int write(
        java.lang.String file,
        int len);

    /**
     * WriteText writes a String to a text file in one batch
     */
    @VTID(24)
    int writeText(
        java.lang.String txt);

}
