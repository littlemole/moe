package mol.wsh  ;

import com4j.*;

@IID("{2A0B9D10-4B87-11D3-A97A-00104B365C9F}")
public interface IFileSystem3 extends mol.wsh.IFileSystem {
    @VTID(32)
    mol.wsh.ITextStream getStandardStream(
        mol.wsh.StandardStreamTypes standardStreamType,
        boolean unicode);

    @VTID(33)
    java.lang.String getFileVersion(
        java.lang.String fileName);

}
