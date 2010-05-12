package mol.office  ;

import com4j.*;

public enum MsoSyncErrorType {
    msoSyncErrorNone, // 0
    msoSyncErrorUnauthorizedUser, // 1
    msoSyncErrorCouldNotConnect, // 2
    msoSyncErrorOutOfSpace, // 3
    msoSyncErrorFileNotFound, // 4
    msoSyncErrorFileTooLarge, // 5
    msoSyncErrorFileInUse, // 6
    msoSyncErrorVirusUpload, // 7
    msoSyncErrorVirusDownload, // 8
    msoSyncErrorUnknownUpload, // 9
    msoSyncErrorUnknownDownload, // 10
    msoSyncErrorCouldNotOpen, // 11
    msoSyncErrorCouldNotUpdate, // 12
    msoSyncErrorCouldNotCompare, // 13
    msoSyncErrorCouldNotResolve, // 14
    msoSyncErrorNoNetwork, // 15
    msoSyncErrorUnknown, // 16
}
