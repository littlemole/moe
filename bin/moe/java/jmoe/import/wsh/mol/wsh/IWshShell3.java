package mol.wsh  ;

import com4j.*;

/**
 * Shell Object Interface
 */
@IID("{41904400-BE18-11D3-A28B-00104BD35090}")
public interface IWshShell3 extends mol.wsh.IWshShell2 {
    @VTID(19)
    mol.wsh.IWshExec exec(
        java.lang.String command);

    @VTID(20)
    java.lang.String currentDirectory();

    @VTID(21)
    void currentDirectory(
        java.lang.String out_Directory);

}
