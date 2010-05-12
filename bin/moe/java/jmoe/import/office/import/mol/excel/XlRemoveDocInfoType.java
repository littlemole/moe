package mol.excel  ;

import com4j.*;

public enum XlRemoveDocInfoType implements ComEnum {
    xlRDIComments(1),
    xlRDIRemovePersonalInformation(4),
    xlRDIEmailHeader(5),
    xlRDIRoutingSlip(6),
    xlRDISendForReview(7),
    xlRDIDocumentProperties(8),
    xlRDIDocumentWorkspace(10),
    xlRDIInkAnnotations(11),
    xlRDIScenarioComments(12),
    xlRDIPublishInfo(13),
    xlRDIDocumentServerProperties(14),
    xlRDIDocumentManagementPolicy(15),
    xlRDIContentType(16),
    xlRDIDefinedNameComments(18),
    xlRDIInactiveDataConnections(19),
    xlRDIPrinterPath(20),
    xlRDIAll(99),
    ;

    private final int value;
    XlRemoveDocInfoType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
