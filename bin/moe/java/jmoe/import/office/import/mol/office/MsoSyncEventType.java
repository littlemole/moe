package mol.office  ;

import com4j.*;

public enum MsoSyncEventType {
    msoSyncEventDownloadInitiated, // 0
    msoSyncEventDownloadSucceeded, // 1
    msoSyncEventDownloadFailed, // 2
    msoSyncEventUploadInitiated, // 3
    msoSyncEventUploadSucceeded, // 4
    msoSyncEventUploadFailed, // 5
    msoSyncEventDownloadNoChange, // 6
    msoSyncEventOffline, // 7
}
