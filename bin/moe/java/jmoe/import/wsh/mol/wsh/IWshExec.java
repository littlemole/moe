package mol.wsh  ;

import com4j.*;

/**
 * WSH Exec Object
 */
@IID("{08FED190-BE19-11D3-A28B-00104BD35090}")
public interface IWshExec extends Com4jObject {
    @VTID(7)
    mol.wsh.WshExecStatus status();

    @VTID(8)
    mol.wsh.ITextStream stdIn();

    @VTID(9)
    mol.wsh.ITextStream stdOut();

    @VTID(10)
    mol.wsh.ITextStream stdErr();

    @VTID(11)
    int processID();

    @VTID(12)
    int exitCode();

    @VTID(13)
    void terminate();

}
