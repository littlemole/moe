package mol.excel  ;

import com4j.*;

@IID("{00024428-0001-0000-C000-000000000046}")
public interface _IQueryTable extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    void name(
        java.lang.String rhs);

    @VTID(12)
    boolean fieldNames();

    @VTID(13)
    void fieldNames(
        boolean rhs);

    @VTID(14)
    boolean rowNumbers();

    @VTID(15)
    void rowNumbers(
        boolean rhs);

    @VTID(16)
    boolean fillAdjacentFormulas();

    @VTID(17)
    void fillAdjacentFormulas(
        boolean rhs);

    @VTID(18)
    boolean hasAutoFormat();

    @VTID(19)
    void hasAutoFormat(
        boolean rhs);

    @VTID(20)
    boolean refreshOnFileOpen();

    @VTID(21)
    void refreshOnFileOpen(
        boolean rhs);

    @VTID(22)
    boolean refreshing();

    @VTID(23)
    boolean fetchedRowOverflow();

    @VTID(24)
    boolean backgroundQuery();

    @VTID(25)
    void backgroundQuery(
        boolean rhs);

    @VTID(26)
    void cancelRefresh();

    @VTID(27)
    mol.excel.XlCellInsertionMode refreshStyle();

    @VTID(28)
    void refreshStyle(
        mol.excel.XlCellInsertionMode rhs);

    @VTID(29)
    boolean enableRefresh();

    @VTID(30)
    void enableRefresh(
        boolean rhs);

    @VTID(31)
    boolean savePassword();

    @VTID(32)
    void savePassword(
        boolean rhs);

    @VTID(33)
    mol.excel.Range destination();

    @VTID(34)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object connection();

    @VTID(35)
    void connection(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(36)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object sql();

    @VTID(37)
    void sql(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(38)
    java.lang.String postText();

    @VTID(39)
    void postText(
        java.lang.String rhs);

    @VTID(40)
    mol.excel.Range resultRange();

    @VTID(41)
    void delete();

    @VTID(42)
    boolean refresh(
        @MarshalAs(NativeType.VARIANT) java.lang.Object backgroundQuery);

    @VTID(43)
    mol.excel.Parameters parameters();

    @VTID(44)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject recordset();

    @VTID(45)
    void recordset(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject rhs);

    @VTID(46)
    boolean saveData();

    @VTID(47)
    void saveData(
        boolean rhs);

    @VTID(48)
    boolean tablesOnlyFromHTML();

    @VTID(49)
    void tablesOnlyFromHTML(
        boolean rhs);

    @VTID(50)
    boolean enableEditing();

    @VTID(51)
    void enableEditing(
        boolean rhs);

    @VTID(52)
    int textFilePlatform();

    @VTID(53)
    void textFilePlatform(
        int rhs);

    @VTID(54)
    int textFileStartRow();

    @VTID(55)
    void textFileStartRow(
        int rhs);

    @VTID(56)
    mol.excel.XlTextParsingType textFileParseType();

    @VTID(57)
    void textFileParseType(
        mol.excel.XlTextParsingType rhs);

    @VTID(58)
    mol.excel.XlTextQualifier textFileTextQualifier();

    @VTID(59)
    void textFileTextQualifier(
        mol.excel.XlTextQualifier rhs);

    @VTID(60)
    boolean textFileConsecutiveDelimiter();

    @VTID(61)
    void textFileConsecutiveDelimiter(
        boolean rhs);

    @VTID(62)
    boolean textFileTabDelimiter();

    @VTID(63)
    void textFileTabDelimiter(
        boolean rhs);

    @VTID(64)
    boolean textFileSemicolonDelimiter();

    @VTID(65)
    void textFileSemicolonDelimiter(
        boolean rhs);

    @VTID(66)
    boolean textFileCommaDelimiter();

    @VTID(67)
    void textFileCommaDelimiter(
        boolean rhs);

    @VTID(68)
    boolean textFileSpaceDelimiter();

    @VTID(69)
    void textFileSpaceDelimiter(
        boolean rhs);

    @VTID(70)
    java.lang.String textFileOtherDelimiter();

    @VTID(71)
    void textFileOtherDelimiter(
        java.lang.String rhs);

    @VTID(72)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object textFileColumnDataTypes();

    @VTID(73)
    void textFileColumnDataTypes(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(74)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object textFileFixedColumnWidths();

    @VTID(75)
    void textFileFixedColumnWidths(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(76)
    boolean preserveColumnInfo();

    @VTID(77)
    void preserveColumnInfo(
        boolean rhs);

    @VTID(78)
    boolean preserveFormatting();

    @VTID(79)
    void preserveFormatting(
        boolean rhs);

    @VTID(80)
    boolean adjustColumnWidth();

    @VTID(81)
    void adjustColumnWidth(
        boolean rhs);

    @VTID(82)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object commandText();

    @VTID(83)
    void commandText(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(84)
    mol.excel.XlCmdType commandType();

    @VTID(85)
    void commandType(
        mol.excel.XlCmdType rhs);

    @VTID(86)
    boolean textFilePromptOnRefresh();

    @VTID(87)
    void textFilePromptOnRefresh(
        boolean rhs);

    @VTID(88)
    mol.excel.XlQueryType queryType();

    @VTID(89)
    boolean maintainConnection();

    @VTID(90)
    void maintainConnection(
        boolean rhs);

    @VTID(91)
    java.lang.String textFileDecimalSeparator();

    @VTID(92)
    void textFileDecimalSeparator(
        java.lang.String rhs);

    @VTID(93)
    java.lang.String textFileThousandsSeparator();

    @VTID(94)
    void textFileThousandsSeparator(
        java.lang.String rhs);

    @VTID(95)
    int refreshPeriod();

    @VTID(96)
    void refreshPeriod(
        int rhs);

    @VTID(97)
    void resetTimer();

    @VTID(98)
    mol.excel.XlWebSelectionType webSelectionType();

    @VTID(99)
    void webSelectionType(
        mol.excel.XlWebSelectionType rhs);

    @VTID(100)
    mol.excel.XlWebFormatting webFormatting();

    @VTID(101)
    void webFormatting(
        mol.excel.XlWebFormatting rhs);

    @VTID(102)
    java.lang.String webTables();

    @VTID(103)
    void webTables(
        java.lang.String rhs);

    @VTID(104)
    boolean webPreFormattedTextToColumns();

    @VTID(105)
    void webPreFormattedTextToColumns(
        boolean rhs);

    @VTID(106)
    boolean webSingleBlockTextImport();

    @VTID(107)
    void webSingleBlockTextImport(
        boolean rhs);

    @VTID(108)
    boolean webDisableDateRecognition();

    @VTID(109)
    void webDisableDateRecognition(
        boolean rhs);

    @VTID(110)
    boolean webConsecutiveDelimitersAsOne();

    @VTID(111)
    void webConsecutiveDelimitersAsOne(
        boolean rhs);

    @VTID(112)
    boolean webDisableRedirections();

    @VTID(113)
    void webDisableRedirections(
        boolean rhs);

    @VTID(114)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object editWebPage();

    @VTID(115)
    void editWebPage(
        @MarshalAs(NativeType.VARIANT) java.lang.Object rhs);

    @VTID(116)
    java.lang.String sourceConnectionFile();

    @VTID(117)
    void sourceConnectionFile(
        java.lang.String rhs);

    @VTID(118)
    java.lang.String sourceDataFile();

    @VTID(119)
    void sourceDataFile(
        java.lang.String rhs);

    @VTID(120)
    mol.excel.XlRobustConnect robustConnect();

    @VTID(121)
    void robustConnect(
        mol.excel.XlRobustConnect rhs);

    @VTID(122)
    boolean textFileTrailingMinusNumbers();

    @VTID(123)
    void textFileTrailingMinusNumbers(
        boolean rhs);

    @VTID(124)
    void saveAsODC(
        java.lang.String odcFileName,
        @MarshalAs(NativeType.VARIANT) java.lang.Object description,
        @MarshalAs(NativeType.VARIANT) java.lang.Object keywords);

    @VTID(125)
    mol.excel.ListObject listObject();

    @VTID(126)
    mol.excel.XlTextVisualLayoutType textFileVisualLayout();

    @VTID(127)
    void textFileVisualLayout(
        mol.excel.XlTextVisualLayoutType rhs);

    @VTID(128)
    mol.excel.WorkbookConnection workbookConnection();

    @VTID(129)
    mol.excel.Sort sort();

}
