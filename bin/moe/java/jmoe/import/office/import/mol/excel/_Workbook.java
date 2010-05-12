package mol.excel  ;

import com4j.*;
import mol.office.*;
import mol.vba.*;

@IID("{000208DA-0000-0000-C000-000000000046}")
public interface _Workbook extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    boolean acceptLabelsInFormulas();

    @VTID(11)
    void acceptLabelsInFormulas(
        boolean rhs);

    @VTID(12)
    void activate(
        int lcid);

    @VTID(13)
    mol.excel._Chart activeChart();

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject activeSheet();

    @VTID(15)
    java.lang.String author(
        int lcid);

    @VTID(16)
    void author(
        int lcid,
        java.lang.String rhs);

    @VTID(17)
    int autoUpdateFrequency();

    @VTID(18)
    void autoUpdateFrequency(
        int rhs);

    @VTID(19)
    boolean autoUpdateSaveChanges();

    @VTID(20)
    void autoUpdateSaveChanges(
        boolean rhs);

    @VTID(21)
    int changeHistoryDuration();

    @VTID(22)
    void changeHistoryDuration(
        int rhs);

    @VTID(23)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject builtinDocumentProperties();

    @VTID(24)
    void changeFileAccess(
        mol.excel.XlFileAccess mode,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writePassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object notify,
        int lcid);

    @VTID(25)
    void changeLink(
        java.lang.String name,
        java.lang.String newName,
        mol.excel.XlLinkType type,
        int lcid);

    @VTID(26)
    mol.excel.Sheets charts();

    @VTID(26)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject charts(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(27)
    void close(
        @MarshalAs(NativeType.VARIANT) java.lang.Object saveChanges,
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object routeWorkbook,
        int lcid);

    @VTID(28)
    java.lang.String codeName();

    @VTID(29)
    java.lang.String _CodeName();

    @VTID(30)
    void _CodeName(
        java.lang.String rhs);

    @VTID(31)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object colors(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid);

    @VTID(32)
    void colors(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index,
        int lcid,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(33)
    mol.office._CommandBars commandBars();

    @VTID(34)
    java.lang.String comments(
        int lcid);

    @VTID(35)
    void comments(
        int lcid,
        java.lang.String rhs);

    @VTID(36)
    mol.excel.XlSaveConflictResolution conflictResolution();

    @VTID(37)
    void conflictResolution(
        mol.excel.XlSaveConflictResolution rhs);

    @VTID(38)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject container();

    @VTID(39)
    boolean createBackup(
        int lcid);

    @VTID(40)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject customDocumentProperties();

    @VTID(41)
    boolean date1904(
        int lcid);

    @VTID(42)
    void date1904(
        int lcid,
        boolean rhs);

    @VTID(43)
    void deleteNumberFormat(
        java.lang.String numberFormat,
        int lcid);

    @VTID(44)
    mol.excel.Sheets dialogSheets();

    @VTID(44)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject dialogSheets(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(45)
    mol.excel.XlDisplayDrawingObjects displayDrawingObjects(
        int lcid);

    @VTID(46)
    void displayDrawingObjects(
        int lcid,
        mol.excel.XlDisplayDrawingObjects rhs);

    @VTID(47)
    boolean exclusiveAccess(
        int lcid);

    @VTID(48)
    mol.excel.XlFileFormat fileFormat(
        int lcid);

    @VTID(49)
    void forwardMailer(
        int lcid);

    @VTID(50)
    java.lang.String fullName(
        int lcid);

    @VTID(51)
    boolean hasMailer(
        int lcid);

    @VTID(52)
    void hasMailer(
        int lcid,
        boolean rhs);

    @VTID(53)
    boolean hasPassword(
        int lcid);

    @VTID(54)
    boolean hasRoutingSlip(
        int lcid);

    @VTID(55)
    void hasRoutingSlip(
        int lcid,
        boolean rhs);

    @VTID(56)
    boolean isAddin();

    @VTID(57)
    void isAddin(
        boolean rhs);

    @VTID(58)
    java.lang.String keywords(
        int lcid);

    @VTID(59)
    void keywords(
        int lcid,
        java.lang.String rhs);

    @VTID(60)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object linkInfo(
        java.lang.String name,
        mol.excel.XlLinkInfo linkInfo,
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object editionRef,
        int lcid);

    @VTID(61)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object linkSources(
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        int lcid);

    @VTID(62)
    mol.excel.Mailer mailer();

    @VTID(63)
    void mergeWorkbook(
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename);

    @VTID(64)
    mol.excel.Sheets modules();

    @VTID(64)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject modules(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(65)
    boolean multiUserEditing(
        int lcid);

    @VTID(66)
    java.lang.String name();

    @VTID(67)
    mol.excel.Names names();

    @VTID(68)
    mol.excel.Window newWindow(
        int lcid);

    @VTID(69)
    java.lang.String onSave(
        int lcid);

    @VTID(70)
    void onSave(
        int lcid,
        java.lang.String rhs);

    @VTID(71)
    java.lang.String onSheetActivate(
        int lcid);

    @VTID(72)
    void onSheetActivate(
        int lcid,
        java.lang.String rhs);

    @VTID(73)
    java.lang.String onSheetDeactivate(
        int lcid);

    @VTID(74)
    void onSheetDeactivate(
        int lcid,
        java.lang.String rhs);

    @VTID(75)
    void openLinks(
        java.lang.String name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnly,
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        int lcid);

    @VTID(76)
    java.lang.String path(
        int lcid);

    @VTID(77)
    boolean personalViewListSettings();

    @VTID(78)
    void personalViewListSettings(
        boolean rhs);

    @VTID(79)
    boolean personalViewPrintSettings();

    @VTID(80)
    void personalViewPrintSettings(
        boolean rhs);

    @VTID(81)
    mol.excel.PivotCaches pivotCaches();

    @VTID(82)
    void post(
        @MarshalAs(NativeType.VARIANT) java.lang.Object destName,
        int lcid);

    @VTID(83)
    boolean precisionAsDisplayed(
        int lcid);

    @VTID(84)
    void precisionAsDisplayed(
        int lcid,
        boolean rhs);

    @VTID(85)
    void __PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        int lcid);

    @VTID(86)
    void printPreview(
        @MarshalAs(NativeType.VARIANT) java.lang.Object enableChanges,
        int lcid);

    @VTID(87)
    void _Protect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object structure,
        @MarshalAs(NativeType.VARIANT) java.lang.Object windows);

    @VTID(88)
    void _ProtectSharing(
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writeResPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnlyRecommended,
        @MarshalAs(NativeType.VARIANT) java.lang.Object createBackup,
        @MarshalAs(NativeType.VARIANT) java.lang.Object sharingPassword);

    @VTID(89)
    boolean protectStructure();

    @VTID(90)
    boolean protectWindows();

    @VTID(91)
    boolean readOnly(
        int lcid);

    @VTID(92)
    boolean _ReadOnlyRecommended(
        int lcid);

    @VTID(93)
    void refreshAll();

    @VTID(94)
    void reply(
        int lcid);

    @VTID(95)
    void replyAll(
        int lcid);

    @VTID(96)
    void removeUser(
        int index);

    @VTID(97)
    int revisionNumber(
        int lcid);

    @VTID(98)
    void route(
        int lcid);

    @VTID(99)
    boolean routed(
        int lcid);

    @VTID(100)
    mol.excel.RoutingSlip routingSlip();

    @VTID(101)
    void runAutoMacros(
        mol.excel.XlRunAutoMacro which,
        int lcid);

    @VTID(102)
    void save(
        int lcid);

    @VTID(103)
    void _SaveAs(
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fileFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writeResPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnlyRecommended,
        @MarshalAs(NativeType.VARIANT) java.lang.Object createBackup,
        mol.excel.XlSaveAsAccessMode accessMode,
        @MarshalAs(NativeType.VARIANT) java.lang.Object conflictResolution,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addToMru,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textCodepage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textVisualLayout,
        int lcid);

    @VTID(104)
    void saveCopyAs(
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        int lcid);

    @VTID(105)
    boolean saved(
        int lcid);

    @VTID(106)
    void saved(
        int lcid,
        boolean rhs);

    @VTID(107)
    boolean saveLinkValues(
        int lcid);

    @VTID(108)
    void saveLinkValues(
        int lcid,
        boolean rhs);

    @VTID(109)
    void sendMail(
        @MarshalAs(NativeType.VARIANT) java.lang.Object recipients,
        @MarshalAs(NativeType.VARIANT) java.lang.Object subject,
        @MarshalAs(NativeType.VARIANT) java.lang.Object returnReceipt,
        int lcid);

    @VTID(110)
    void sendMailer(
        @MarshalAs(NativeType.VARIANT) java.lang.Object fileFormat,
        mol.excel.XlPriority priority,
        int lcid);

    @VTID(111)
    void setLinkOnData(
        java.lang.String name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object procedure,
        int lcid);

    @VTID(112)
    mol.excel.Sheets sheets();

    @VTID(112)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject sheets(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(113)
    boolean showConflictHistory(
        int lcid);

    @VTID(114)
    void showConflictHistory(
        int lcid,
        boolean rhs);

    @VTID(115)
    mol.excel.Styles styles();

    @VTID(116)
    java.lang.String subject(
        int lcid);

    @VTID(117)
    void subject(
        int lcid,
        java.lang.String rhs);

    @VTID(118)
    java.lang.String title(
        int lcid);

    @VTID(119)
    void title(
        int lcid,
        java.lang.String rhs);

    @VTID(120)
    void unprotect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        int lcid);

    @VTID(121)
    void unprotectSharing(
        @MarshalAs(NativeType.VARIANT) java.lang.Object sharingPassword);

    @VTID(122)
    void updateFromFile(
        int lcid);

    @VTID(123)
    void updateLink(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object type,
        int lcid);

    @VTID(124)
    boolean updateRemoteReferences(
        int lcid);

    @VTID(125)
    void updateRemoteReferences(
        int lcid,
        boolean rhs);

    @VTID(126)
    boolean userControl();

    @VTID(127)
    void userControl(
        boolean rhs);

    @VTID(128)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object userStatus(
        int lcid);

    @VTID(129)
    mol.excel.CustomViews customViews();

    @VTID(130)
    mol.excel.Windows windows();

    @VTID(131)
    mol.excel.Sheets worksheets();

    @VTID(131)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject worksheets(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(132)
    boolean writeReserved(
        int lcid);

    @VTID(133)
    java.lang.String writeReservedBy(
        int lcid);

    @VTID(134)
    mol.excel.Sheets excel4IntlMacroSheets();

    @VTID(134)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject excel4IntlMacroSheets(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(135)
    mol.excel.Sheets excel4MacroSheets();

    @VTID(135)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.excel.Sheets.class})
    com4j.Com4jObject excel4MacroSheets(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(136)
    boolean templateRemoveExtData();

    @VTID(137)
    void templateRemoveExtData(
        boolean rhs);

    @VTID(138)
    void highlightChangesOptions(
        @MarshalAs(NativeType.VARIANT) java.lang.Object when,
        @MarshalAs(NativeType.VARIANT) java.lang.Object who,
        @MarshalAs(NativeType.VARIANT) java.lang.Object where);

    @VTID(139)
    boolean highlightChangesOnScreen();

    @VTID(140)
    void highlightChangesOnScreen(
        boolean rhs);

    @VTID(141)
    boolean keepChangeHistory();

    @VTID(142)
    void keepChangeHistory(
        boolean rhs);

    @VTID(143)
    boolean listChangesOnNewSheet();

    @VTID(144)
    void listChangesOnNewSheet(
        boolean rhs);

    @VTID(145)
    void purgeChangeHistoryNow(
        int days,
        @MarshalAs(NativeType.VARIANT) java.lang.Object sharingPassword);

    @VTID(146)
    void acceptAllChanges(
        @MarshalAs(NativeType.VARIANT) java.lang.Object when,
        @MarshalAs(NativeType.VARIANT) java.lang.Object who,
        @MarshalAs(NativeType.VARIANT) java.lang.Object where);

    @VTID(147)
    void rejectAllChanges(
        @MarshalAs(NativeType.VARIANT) java.lang.Object when,
        @MarshalAs(NativeType.VARIANT) java.lang.Object who,
        @MarshalAs(NativeType.VARIANT) java.lang.Object where);

    @VTID(148)
    void pivotTableWizard(
        @MarshalAs(NativeType.VARIANT) java.lang.Object sourceType,
        @MarshalAs(NativeType.VARIANT) java.lang.Object sourceData,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tableDestination,
        @MarshalAs(NativeType.VARIANT) java.lang.Object tableName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rowGrand,
        @MarshalAs(NativeType.VARIANT) java.lang.Object columnGrand,
        @MarshalAs(NativeType.VARIANT) java.lang.Object saveData,
        @MarshalAs(NativeType.VARIANT) java.lang.Object hasAutoFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object autoPage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object reserved,
        @MarshalAs(NativeType.VARIANT) java.lang.Object backgroundQuery,
        @MarshalAs(NativeType.VARIANT) java.lang.Object optimizeCache,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pageFieldOrder,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pageFieldWrapCount,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readData,
        @MarshalAs(NativeType.VARIANT) java.lang.Object connection,
        int lcid);

    @VTID(149)
    void resetColors();

    @VTID(150)
    mol.vba._VBProject vbProject();

    @VTID(151)
    void followHyperlink(
        java.lang.String address,
        @MarshalAs(NativeType.VARIANT) java.lang.Object subAddress,
        @MarshalAs(NativeType.VARIANT) java.lang.Object newWindow,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addHistory,
        @MarshalAs(NativeType.VARIANT) java.lang.Object extraInfo,
        @MarshalAs(NativeType.VARIANT) java.lang.Object method,
        @MarshalAs(NativeType.VARIANT) java.lang.Object headerInfo);

    @VTID(152)
    void addToFavorites();

    @VTID(153)
    boolean isInplace();

    @VTID(154)
    void _PrintOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName,
        int lcid);

    @VTID(155)
    void webPagePreview();

    @VTID(156)
    mol.excel.PublishObjects publishObjects();

    @VTID(157)
    mol.excel.WebOptions webOptions();

    @VTID(158)
    void reloadAs(
        mol.office.MsoEncoding encoding);

    @VTID(159)
    mol.office.HTMLProject htmlProject();

    @VTID(160)
    boolean envelopeVisible();

    @VTID(161)
    void envelopeVisible(
        boolean rhs);

    @VTID(162)
    int calculationVersion();

    @VTID(163)
    void dummy17(
        int calcid);

    @VTID(164)
    void sblt(
        java.lang.String s);

    @VTID(165)
    boolean vbaSigned();

    @VTID(166)
    boolean showPivotTableFieldList();

    @VTID(167)
    void showPivotTableFieldList(
        boolean rhs);

    @VTID(168)
    mol.excel.XlUpdateLinks updateLinks();

    @VTID(169)
    void updateLinks(
        mol.excel.XlUpdateLinks rhs);

    @VTID(170)
    void breakLink(
        java.lang.String name,
        mol.excel.XlLinkType type);

    @VTID(171)
    void dummy16();

    @VTID(172)
    void saveAs(
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fileFormat,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writeResPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnlyRecommended,
        @MarshalAs(NativeType.VARIANT) java.lang.Object createBackup,
        mol.excel.XlSaveAsAccessMode accessMode,
        @MarshalAs(NativeType.VARIANT) java.lang.Object conflictResolution,
        @MarshalAs(NativeType.VARIANT) java.lang.Object addToMru,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textCodepage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object textVisualLayout,
        @MarshalAs(NativeType.VARIANT) java.lang.Object local,
        int lcid);

    @VTID(173)
    boolean enableAutoRecover();

    @VTID(174)
    void enableAutoRecover(
        boolean rhs);

    @VTID(175)
    boolean removePersonalInformation();

    @VTID(176)
    void removePersonalInformation(
        boolean rhs);

    @VTID(177)
    java.lang.String fullNameURLEncoded(
        int lcid);

    @VTID(178)
    void checkIn(
        @MarshalAs(NativeType.VARIANT) java.lang.Object saveChanges,
        @MarshalAs(NativeType.VARIANT) java.lang.Object comments,
        @MarshalAs(NativeType.VARIANT) java.lang.Object makePublic);

    @VTID(179)
    boolean canCheckIn();

    @VTID(180)
    void sendForReview(
        @MarshalAs(NativeType.VARIANT) java.lang.Object recipients,
        @MarshalAs(NativeType.VARIANT) java.lang.Object subject,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showMessage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object includeAttachment);

    @VTID(181)
    void replyWithChanges(
        @MarshalAs(NativeType.VARIANT) java.lang.Object showMessage);

    @VTID(182)
    void endReview();

    @VTID(183)
    java.lang.String password();

    @VTID(184)
    void password(
        java.lang.String rhs);

    @VTID(185)
    java.lang.String writePassword();

    @VTID(186)
    void writePassword(
        java.lang.String rhs);

    @VTID(187)
    java.lang.String passwordEncryptionProvider();

    @VTID(188)
    java.lang.String passwordEncryptionAlgorithm();

    @VTID(189)
    int passwordEncryptionKeyLength();

    @VTID(190)
    void setPasswordEncryptionOptions(
        @MarshalAs(NativeType.VARIANT) java.lang.Object passwordEncryptionProvider,
        @MarshalAs(NativeType.VARIANT) java.lang.Object passwordEncryptionAlgorithm,
        @MarshalAs(NativeType.VARIANT) java.lang.Object passwordEncryptionKeyLength,
        @MarshalAs(NativeType.VARIANT) java.lang.Object passwordEncryptionFileProperties);

    @VTID(191)
    boolean passwordEncryptionFileProperties();

    @VTID(192)
    boolean readOnlyRecommended();

    @VTID(193)
    void readOnlyRecommended(
        boolean rhs);

    @VTID(194)
    void protect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object structure,
        @MarshalAs(NativeType.VARIANT) java.lang.Object windows);

    @VTID(195)
    mol.excel.SmartTagOptions smartTagOptions();

    @VTID(196)
    void recheckSmartTags();

    @VTID(197)
    mol.office.Permission permission();

    @VTID(197)
    @ReturnValue(defaultPropertyThrough={mol.office.Permission.class})
    mol.office.UserPermission permission(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(198)
    mol.office.SharedWorkspace sharedWorkspace();

    @VTID(199)
    mol.office.Sync sync();

    @VTID(200)
    void sendFaxOverInternet(
        @MarshalAs(NativeType.VARIANT) java.lang.Object recipients,
        @MarshalAs(NativeType.VARIANT) java.lang.Object subject,
        @MarshalAs(NativeType.VARIANT) java.lang.Object showMessage);

    @VTID(201)
    mol.excel.XmlNamespaces xmlNamespaces();

    @VTID(202)
    mol.excel.XmlMaps xmlMaps();

    @VTID(203)
    mol.excel.XlXmlImportResult xmlImport(
        java.lang.String url,
        Holder<mol.excel.XmlMap> importMap,
        @MarshalAs(NativeType.VARIANT) java.lang.Object overwrite,
        @MarshalAs(NativeType.VARIANT) java.lang.Object destination);

    @VTID(204)
    mol.office.SmartDocument smartDocument();

    @VTID(205)
    mol.office.DocumentLibraryVersions documentLibraryVersions();

    @VTID(205)
    @ReturnValue(defaultPropertyThrough={mol.office.DocumentLibraryVersions.class})
    mol.office.DocumentLibraryVersion documentLibraryVersions(
        int lIndex);

    @VTID(206)
    boolean inactiveListBorderVisible();

    @VTID(207)
    void inactiveListBorderVisible(
        boolean rhs);

    @VTID(208)
    boolean displayInkComments();

    @VTID(209)
    void displayInkComments(
        boolean rhs);

    @VTID(210)
    mol.excel.XlXmlImportResult xmlImportXml(
        java.lang.String data,
        Holder<mol.excel.XmlMap> importMap,
        @MarshalAs(NativeType.VARIANT) java.lang.Object overwrite,
        @MarshalAs(NativeType.VARIANT) java.lang.Object destination);

    @VTID(211)
    void saveAsXMLData(
        java.lang.String filename,
        mol.excel.XmlMap map);

    @VTID(212)
    void toggleFormsDesign();

    @VTID(213)
    mol.office.MetaProperties contentTypeProperties();

    @VTID(213)
    @ReturnValue(defaultPropertyThrough={mol.office.MetaProperties.class})
    mol.office.MetaProperty contentTypeProperties(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(214)
    mol.excel.Connections connections();

    @VTID(215)
    void removeDocumentInformation(
        mol.excel.XlRemoveDocInfoType removeDocInfoType);

    @VTID(216)
    mol.office.SignatureSet signatures();

    @VTID(216)
    @ReturnValue(defaultPropertyThrough={mol.office.SignatureSet.class})
    mol.office.Signature signatures(
        int iSig);

    @VTID(217)
    void checkInWithVersion(
        @MarshalAs(NativeType.VARIANT) java.lang.Object saveChanges,
        @MarshalAs(NativeType.VARIANT) java.lang.Object comments,
        @MarshalAs(NativeType.VARIANT) java.lang.Object makePublic,
        @MarshalAs(NativeType.VARIANT) java.lang.Object versionType);

    @VTID(218)
    mol.office.ServerPolicy serverPolicy();

    @VTID(218)
    @ReturnValue(defaultPropertyThrough={mol.office.ServerPolicy.class})
    mol.office.PolicyItem serverPolicy(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(219)
    void lockServerFile();

    @VTID(220)
    mol.office.DocumentInspectors documentInspectors();

    @VTID(220)
    @ReturnValue(defaultPropertyThrough={mol.office.DocumentInspectors.class})
    mol.office.DocumentInspector documentInspectors(
        int index);

    @VTID(221)
    mol.office.WorkflowTasks getWorkflowTasks();

    @VTID(221)
    @ReturnValue(defaultPropertyThrough={mol.office.WorkflowTasks.class})
    mol.office.WorkflowTask getWorkflowTasks(
        int index);

    @VTID(222)
    mol.office.WorkflowTemplates getWorkflowTemplates();

    @VTID(222)
    @ReturnValue(defaultPropertyThrough={mol.office.WorkflowTemplates.class})
    mol.office.WorkflowTemplate getWorkflowTemplates(
        int index);

    @VTID(223)
    void printOut(
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object copies,
        @MarshalAs(NativeType.VARIANT) java.lang.Object preview,
        @MarshalAs(NativeType.VARIANT) java.lang.Object activePrinter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object printToFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object collate,
        @MarshalAs(NativeType.VARIANT) java.lang.Object prToFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignorePrintAreas,
        int lcid);

    @VTID(224)
    mol.excel.ServerViewableItems serverViewableItems();

    @VTID(225)
    mol.excel.TableStyles tableStyles();

    @VTID(226)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object defaultTableStyle();

    @VTID(227)
    void defaultTableStyle(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(228)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object defaultPivotTableStyle();

    @VTID(229)
    void defaultPivotTableStyle(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(230)
    boolean checkCompatibility();

    @VTID(231)
    void checkCompatibility(
        boolean rhs);

    @VTID(232)
    boolean hasVBProject();

    @VTID(233)
    mol.office._CustomXMLParts customXMLParts();

    @VTID(234)
    boolean _final();

    @VTID(235)
    void _final(
        boolean rhs);

    @VTID(236)
    mol.excel.Research research();

    @VTID(237)
    mol.office.OfficeTheme theme();

    @VTID(238)
    void applyTheme(
        java.lang.String filename);

    @VTID(239)
    boolean excel8CompatibilityMode();

    @VTID(240)
    boolean connectionsDisabled();

    @VTID(241)
    void enableConnections();

    @VTID(242)
    boolean showPivotChartActiveFields();

    @VTID(243)
    void showPivotChartActiveFields(
        boolean rhs);

    @VTID(244)
    void exportAsFixedFormat(
        mol.excel.XlFixedFormatType type,
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object quality,
        @MarshalAs(NativeType.VARIANT) java.lang.Object includeDocProperties,
        @MarshalAs(NativeType.VARIANT) java.lang.Object ignorePrintAreas,
        @MarshalAs(NativeType.VARIANT) java.lang.Object from,
        @MarshalAs(NativeType.VARIANT) java.lang.Object to,
        @MarshalAs(NativeType.VARIANT) java.lang.Object openAfterPublish,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fixedFormatExtClassPtr);

    @VTID(245)
    mol.excel.IconSets iconSets();

    @VTID(246)
    java.lang.String encryptionProvider();

    @VTID(247)
    void encryptionProvider(
        java.lang.String rhs);

    @VTID(248)
    boolean doNotPromptForConvert();

    @VTID(249)
    void doNotPromptForConvert(
        boolean rhs);

    @VTID(250)
    boolean forceFullCalculation();

    @VTID(251)
    void forceFullCalculation(
        boolean rhs);

    @VTID(252)
    void protectSharing(
        @MarshalAs(NativeType.VARIANT) java.lang.Object filename,
        @MarshalAs(NativeType.VARIANT) java.lang.Object password,
        @MarshalAs(NativeType.VARIANT) java.lang.Object writeResPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object readOnlyRecommended,
        @MarshalAs(NativeType.VARIANT) java.lang.Object createBackup,
        @MarshalAs(NativeType.VARIANT) java.lang.Object sharingPassword,
        @MarshalAs(NativeType.VARIANT) java.lang.Object fileFormat);

}
