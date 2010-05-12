package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface _QueryTable extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(110)
    @PropPut
    void name(
        java.lang.String rhs);

    @DISPID(1584)
    @PropGet
    boolean fieldNames();

    @DISPID(1584)
    @PropPut
    void fieldNames(
        boolean rhs);

    @DISPID(1585)
    @PropGet
    boolean rowNumbers();

    @DISPID(1585)
    @PropPut
    void rowNumbers(
        boolean rhs);

    @DISPID(1586)
    @PropGet
    boolean fillAdjacentFormulas();

    @DISPID(1586)
    @PropPut
    void fillAdjacentFormulas(
        boolean rhs);

    @DISPID(695)
    @PropGet
    boolean hasAutoFormat();

    @DISPID(695)
    @PropPut
    void hasAutoFormat(
        boolean rhs);

    @DISPID(1479)
    @PropGet
    boolean refreshOnFileOpen();

    @DISPID(1479)
    @PropPut
    void refreshOnFileOpen(
        boolean rhs);

    @DISPID(1587)
    @PropGet
    boolean refreshing();

    @DISPID(1588)
    @PropGet
    boolean fetchedRowOverflow();

    @DISPID(1427)
    @PropGet
    boolean backgroundQuery();

    @DISPID(1427)
    @PropPut
    void backgroundQuery(
        boolean rhs);

    @DISPID(1589)
    void cancelRefresh();

    @DISPID(1590)
    @PropGet
    mol.excel.XlCellInsertionMode refreshStyle();

    @DISPID(1590)
    @PropPut
    void refreshStyle(
        mol.excel.XlCellInsertionMode rhs);

    @DISPID(1477)
    @PropGet
    boolean enableRefresh();

    @DISPID(1477)
    @PropPut
    void enableRefresh(
        boolean rhs);

    @DISPID(1481)
    @PropGet
    boolean savePassword();

    @DISPID(1481)
    @PropPut
    void savePassword(
        boolean rhs);

    @DISPID(681)
    @PropGet
    mol.excel.Range destination();

    @DISPID(1432)
    @PropGet
    java.lang.Object connection();

    @DISPID(1432)
    @PropPut
    void connection(
        java.lang.Object rhs);

    @DISPID(1480)
    @PropGet
    java.lang.Object sql();

    @DISPID(1480)
    @PropPut
    void sql(
        java.lang.Object rhs);

    @DISPID(1591)
    @PropGet
    java.lang.String postText();

    @DISPID(1591)
    @PropPut
    void postText(
        java.lang.String rhs);

    @DISPID(1592)
    @PropGet
    mol.excel.Range resultRange();

    @DISPID(117)
    void delete();

    @DISPID(1417)
    boolean refresh(
        java.lang.Object backgroundQuery);

    @DISPID(1593)
    @PropGet
    mol.excel.Parameters parameters();

    @DISPID(1165)
    @PropGet
    com4j.Com4jObject recordset();

    @DISPID(1165)
    @PropPut
    void recordset(
        com4j.Com4jObject rhs);

    @DISPID(692)
    @PropGet
    boolean saveData();

    @DISPID(692)
    @PropPut
    void saveData(
        boolean rhs);

    @DISPID(1594)
    @PropGet
    boolean tablesOnlyFromHTML();

    @DISPID(1594)
    @PropPut
    void tablesOnlyFromHTML(
        boolean rhs);

    @DISPID(1595)
    @PropGet
    boolean enableEditing();

    @DISPID(1595)
    @PropPut
    void enableEditing(
        boolean rhs);

    @DISPID(1855)
    @PropGet
    int textFilePlatform();

    @DISPID(1855)
    @PropPut
    void textFilePlatform(
        int rhs);

    @DISPID(1856)
    @PropGet
    int textFileStartRow();

    @DISPID(1856)
    @PropPut
    void textFileStartRow(
        int rhs);

    @DISPID(1857)
    @PropGet
    mol.excel.XlTextParsingType textFileParseType();

    @DISPID(1857)
    @PropPut
    void textFileParseType(
        mol.excel.XlTextParsingType rhs);

    @DISPID(1858)
    @PropGet
    mol.excel.XlTextQualifier textFileTextQualifier();

    @DISPID(1858)
    @PropPut
    void textFileTextQualifier(
        mol.excel.XlTextQualifier rhs);

    @DISPID(1859)
    @PropGet
    boolean textFileConsecutiveDelimiter();

    @DISPID(1859)
    @PropPut
    void textFileConsecutiveDelimiter(
        boolean rhs);

    @DISPID(1860)
    @PropGet
    boolean textFileTabDelimiter();

    @DISPID(1860)
    @PropPut
    void textFileTabDelimiter(
        boolean rhs);

    @DISPID(1861)
    @PropGet
    boolean textFileSemicolonDelimiter();

    @DISPID(1861)
    @PropPut
    void textFileSemicolonDelimiter(
        boolean rhs);

    @DISPID(1862)
    @PropGet
    boolean textFileCommaDelimiter();

    @DISPID(1862)
    @PropPut
    void textFileCommaDelimiter(
        boolean rhs);

    @DISPID(1863)
    @PropGet
    boolean textFileSpaceDelimiter();

    @DISPID(1863)
    @PropPut
    void textFileSpaceDelimiter(
        boolean rhs);

    @DISPID(1864)
    @PropGet
    java.lang.String textFileOtherDelimiter();

    @DISPID(1864)
    @PropPut
    void textFileOtherDelimiter(
        java.lang.String rhs);

    @DISPID(1865)
    @PropGet
    java.lang.Object textFileColumnDataTypes();

    @DISPID(1865)
    @PropPut
    void textFileColumnDataTypes(
        java.lang.Object rhs);

    @DISPID(1866)
    @PropGet
    java.lang.Object textFileFixedColumnWidths();

    @DISPID(1866)
    @PropPut
    void textFileFixedColumnWidths(
        java.lang.Object rhs);

    @DISPID(1867)
    @PropGet
    boolean preserveColumnInfo();

    @DISPID(1867)
    @PropPut
    void preserveColumnInfo(
        boolean rhs);

    @DISPID(1500)
    @PropGet
    boolean preserveFormatting();

    @DISPID(1500)
    @PropPut
    void preserveFormatting(
        boolean rhs);

    @DISPID(1868)
    @PropGet
    boolean adjustColumnWidth();

    @DISPID(1868)
    @PropPut
    void adjustColumnWidth(
        boolean rhs);

    @DISPID(1829)
    @PropGet
    java.lang.Object commandText();

    @DISPID(1829)
    @PropPut
    void commandText(
        java.lang.Object rhs);

    @DISPID(1830)
    @PropGet
    mol.excel.XlCmdType commandType();

    @DISPID(1830)
    @PropPut
    void commandType(
        mol.excel.XlCmdType rhs);

    @DISPID(1869)
    @PropGet
    boolean textFilePromptOnRefresh();

    @DISPID(1869)
    @PropPut
    void textFilePromptOnRefresh(
        boolean rhs);

    @DISPID(1831)
    @PropGet
    mol.excel.XlQueryType queryType();

    @DISPID(1832)
    @PropGet
    boolean maintainConnection();

    @DISPID(1832)
    @PropPut
    void maintainConnection(
        boolean rhs);

    @DISPID(1870)
    @PropGet
    java.lang.String textFileDecimalSeparator();

    @DISPID(1870)
    @PropPut
    void textFileDecimalSeparator(
        java.lang.String rhs);

    @DISPID(1871)
    @PropGet
    java.lang.String textFileThousandsSeparator();

    @DISPID(1871)
    @PropPut
    void textFileThousandsSeparator(
        java.lang.String rhs);

    @DISPID(1833)
    @PropGet
    int refreshPeriod();

    @DISPID(1833)
    @PropPut
    void refreshPeriod(
        int rhs);

    @DISPID(1834)
    void resetTimer();

    @DISPID(1872)
    @PropGet
    mol.excel.XlWebSelectionType webSelectionType();

    @DISPID(1872)
    @PropPut
    void webSelectionType(
        mol.excel.XlWebSelectionType rhs);

    @DISPID(1873)
    @PropGet
    mol.excel.XlWebFormatting webFormatting();

    @DISPID(1873)
    @PropPut
    void webFormatting(
        mol.excel.XlWebFormatting rhs);

    @DISPID(1874)
    @PropGet
    java.lang.String webTables();

    @DISPID(1874)
    @PropPut
    void webTables(
        java.lang.String rhs);

    @DISPID(1875)
    @PropGet
    boolean webPreFormattedTextToColumns();

    @DISPID(1875)
    @PropPut
    void webPreFormattedTextToColumns(
        boolean rhs);

    @DISPID(1876)
    @PropGet
    boolean webSingleBlockTextImport();

    @DISPID(1876)
    @PropPut
    void webSingleBlockTextImport(
        boolean rhs);

    @DISPID(1877)
    @PropGet
    boolean webDisableDateRecognition();

    @DISPID(1877)
    @PropPut
    void webDisableDateRecognition(
        boolean rhs);

    @DISPID(1878)
    @PropGet
    boolean webConsecutiveDelimitersAsOne();

    @DISPID(1878)
    @PropPut
    void webConsecutiveDelimitersAsOne(
        boolean rhs);

    @DISPID(2162)
    @PropGet
    boolean webDisableRedirections();

    @DISPID(2162)
    @PropPut
    void webDisableRedirections(
        boolean rhs);

    @DISPID(2163)
    @PropGet
    java.lang.Object editWebPage();

    @DISPID(2163)
    @PropPut
    void editWebPage(
        java.lang.Object rhs);

    @DISPID(2079)
    @PropGet
    java.lang.String sourceConnectionFile();

    @DISPID(2079)
    @PropPut
    void sourceConnectionFile(
        java.lang.String rhs);

    @DISPID(2080)
    @PropGet
    java.lang.String sourceDataFile();

    @DISPID(2080)
    @PropPut
    void sourceDataFile(
        java.lang.String rhs);

    @DISPID(2081)
    @PropGet
    mol.excel.XlRobustConnect robustConnect();

    @DISPID(2081)
    @PropPut
    void robustConnect(
        mol.excel.XlRobustConnect rhs);

    @DISPID(2164)
    @PropGet
    boolean textFileTrailingMinusNumbers();

    @DISPID(2164)
    @PropPut
    void textFileTrailingMinusNumbers(
        boolean rhs);

    @DISPID(2082)
    void saveAsODC(
        java.lang.String odcFileName,
        java.lang.Object description,
        java.lang.Object keywords);

    @DISPID(2257)
    @PropGet
    mol.excel.ListObject listObject();

    @DISPID(2245)
    @PropGet
    mol.excel.XlTextVisualLayoutType textFileVisualLayout();

    @DISPID(2245)
    @PropPut
    void textFileVisualLayout(
        mol.excel.XlTextVisualLayoutType rhs);

    @DISPID(2544)
    @PropGet
    mol.excel.WorkbookConnection workbookConnection();

    @DISPID(880)
    @PropGet
    mol.excel.Sort sort();

}
