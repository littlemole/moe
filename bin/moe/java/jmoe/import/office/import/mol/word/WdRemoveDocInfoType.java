package mol.word  ;

import com4j.*;

public enum WdRemoveDocInfoType implements ComEnum {
    wdRDIComments(1),
    wdRDIRevisions(2),
    wdRDIVersions(3),
    wdRDIRemovePersonalInformation(4),
    wdRDIEmailHeader(5),
    wdRDIRoutingSlip(6),
    wdRDISendForReview(7),
    wdRDIDocumentProperties(8),
    wdRDITemplate(9),
    wdRDIDocumentWorkspace(10),
    wdRDIInkAnnotations(11),
    wdRDIDocumentServerProperties(14),
    wdRDIDocumentManagementPolicy(15),
    wdRDIContentType(16),
    wdRDIAll(99),
    ;

    private final int value;
    WdRemoveDocInfoType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
