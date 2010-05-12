package mol.office  ;

import com4j.*;

public enum CertificateVerificationResults {
    certverresError, // 0
    certverresVerifying, // 1
    certverresUnverified, // 2
    certverresValid, // 3
    certverresInvalid, // 4
    certverresExpired, // 5
    certverresRevoked, // 6
    certverresUntrusted, // 7
}
