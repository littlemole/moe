package mol.word  ;

import com4j.*;

@IID("{0002096C-0000-0000-C000-000000000046}")
public interface Documents extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word._Application application();

    @VTID(10)
    int creator();

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(12)
    @DefaultMethod
    mol.word._Document item(
        java.lang.Object index);

    @VTID(13)
    void close(
        java.lang.Object saveChanges,
        java.lang.Object originalFormat,
        java.lang.Object routeDocument);

    @VTID(14)
    mol.word._Document addOld(
        java.lang.Object template,
        java.lang.Object newTemplate);

    @VTID(15)
    mol.word._Document openOld(
        java.lang.Object fileName,
        java.lang.Object confirmConversions,
        java.lang.Object readOnly,
        java.lang.Object addToRecentFiles,
        java.lang.Object passwordDocument,
        java.lang.Object passwordTemplate,
        java.lang.Object revert,
        java.lang.Object writePasswordDocument,
        java.lang.Object writePasswordTemplate,
        java.lang.Object format);

    @VTID(16)
    void save(
        java.lang.Object noPrompt,
        java.lang.Object originalFormat);

    @VTID(17)
    mol.word._Document add(
        java.lang.Object template,
        java.lang.Object newTemplate,
        java.lang.Object documentType,
        java.lang.Object visible);

    @VTID(18)
    mol.word._Document open2000(
        java.lang.Object fileName,
        java.lang.Object confirmConversions,
        java.lang.Object readOnly,
        java.lang.Object addToRecentFiles,
        java.lang.Object passwordDocument,
        java.lang.Object passwordTemplate,
        java.lang.Object revert,
        java.lang.Object writePasswordDocument,
        java.lang.Object writePasswordTemplate,
        java.lang.Object format,
        java.lang.Object encoding,
        java.lang.Object visible);

    @VTID(19)
    void checkOut(
        java.lang.String fileName);

    @VTID(20)
    boolean canCheckOut(
        java.lang.String fileName);

    @VTID(21)
    mol.word._Document open2002(
        java.lang.Object fileName,
        java.lang.Object confirmConversions,
        java.lang.Object readOnly,
        java.lang.Object addToRecentFiles,
        java.lang.Object passwordDocument,
        java.lang.Object passwordTemplate,
        java.lang.Object revert,
        java.lang.Object writePasswordDocument,
        java.lang.Object writePasswordTemplate,
        java.lang.Object format,
        java.lang.Object encoding,
        java.lang.Object visible,
        java.lang.Object openAndRepair,
        java.lang.Object documentDirection,
        java.lang.Object noEncodingDialog);

    @VTID(22)
    mol.word._Document open(
        java.lang.Object fileName,
        java.lang.Object confirmConversions,
        java.lang.Object readOnly,
        java.lang.Object addToRecentFiles,
        java.lang.Object passwordDocument,
        java.lang.Object passwordTemplate,
        java.lang.Object revert,
        java.lang.Object writePasswordDocument,
        java.lang.Object writePasswordTemplate,
        java.lang.Object format,
        java.lang.Object encoding,
        java.lang.Object visible,
        java.lang.Object openAndRepair,
        java.lang.Object documentDirection,
        java.lang.Object noEncodingDialog,
        java.lang.Object xmlTransform);

    @VTID(23)
    mol.word._Document openNoRepairDialog(
        java.lang.Object fileName,
        java.lang.Object confirmConversions,
        java.lang.Object readOnly,
        java.lang.Object addToRecentFiles,
        java.lang.Object passwordDocument,
        java.lang.Object passwordTemplate,
        java.lang.Object revert,
        java.lang.Object writePasswordDocument,
        java.lang.Object writePasswordTemplate,
        java.lang.Object format,
        java.lang.Object encoding,
        java.lang.Object visible,
        java.lang.Object openAndRepair,
        java.lang.Object documentDirection,
        java.lang.Object noEncodingDialog,
        java.lang.Object xmlTransform);

    @VTID(24)
    mol.word._Document addBlogDocument(
        java.lang.String providerID,
        java.lang.String postURL,
        java.lang.String blogName,
        java.lang.String postID);

}
