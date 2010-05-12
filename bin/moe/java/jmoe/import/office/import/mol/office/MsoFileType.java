package mol.office  ;

import com4j.*;

public enum MsoFileType implements ComEnum {
    msoFileTypeAllFiles(1),
    msoFileTypeOfficeFiles(2),
    msoFileTypeWordDocuments(3),
    msoFileTypeExcelWorkbooks(4),
    msoFileTypePowerPointPresentations(5),
    msoFileTypeBinders(6),
    msoFileTypeDatabases(7),
    msoFileTypeTemplates(8),
    msoFileTypeOutlookItems(9),
    msoFileTypeMailItem(10),
    msoFileTypeCalendarItem(11),
    msoFileTypeContactItem(12),
    msoFileTypeNoteItem(13),
    msoFileTypeJournalItem(14),
    msoFileTypeTaskItem(15),
    msoFileTypePhotoDrawFiles(16),
    msoFileTypeDataConnectionFiles(17),
    msoFileTypePublisherFiles(18),
    msoFileTypeProjectFiles(19),
    msoFileTypeDocumentImagingFiles(20),
    msoFileTypeVisioFiles(21),
    msoFileTypeDesignerFiles(22),
    msoFileTypeWebPages(23),
    ;

    private final int value;
    MsoFileType(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
