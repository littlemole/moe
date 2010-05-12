package mol.office  ;

import com4j.*;

@IID("{000C0332-0000-0000-C000-000000000046}")
public interface FileSearch extends mol.office._IMsoDispObj {
    @VTID(9)
    boolean searchSubFolders();

    @VTID(10)
    void searchSubFolders(
        boolean searchSubFoldersRetVal);

    @VTID(11)
    boolean matchTextExactly();

    @VTID(12)
    void matchTextExactly(
        boolean matchTextRetVal);

    @VTID(13)
    boolean matchAllWordForms();

    @VTID(14)
    void matchAllWordForms(
        boolean matchAllWordFormsRetVal);

    @VTID(15)
    java.lang.String fileName();

    @VTID(16)
    void fileName(
        java.lang.String fileNameRetVal);

    @VTID(17)
    mol.office.MsoFileType fileType();

    @VTID(18)
    void fileType(
        mol.office.MsoFileType fileTypeRetVal);

    @VTID(19)
    mol.office.MsoLastModified lastModified();

    @VTID(20)
    void lastModified(
        mol.office.MsoLastModified lastModifiedRetVal);

    @VTID(21)
    java.lang.String textOrProperty();

    @VTID(22)
    void textOrProperty(
        java.lang.String textOrProperty);

    @VTID(23)
    java.lang.String lookIn();

    @VTID(24)
    void lookIn(
        java.lang.String lookInRetVal);

    @VTID(25)
    int execute(
        mol.office.MsoSortBy sortBy,
        mol.office.MsoSortOrder sortOrder,
        boolean alwaysAccurate);

    @VTID(26)
    void newSearch();

    @VTID(27)
    mol.office.FoundFiles foundFiles();

    @VTID(27)
    @ReturnValue(defaultPropertyThrough={mol.office.FoundFiles.class})
    java.lang.String foundFiles(
        int index,
        int lcid);

    @VTID(28)
    mol.office.PropertyTests propertyTests();

    @VTID(28)
    @ReturnValue(defaultPropertyThrough={mol.office.PropertyTests.class})
    mol.office.PropertyTest propertyTests(
        int index,
        int lcid);

    @VTID(29)
    mol.office.SearchScopes searchScopes();

    @VTID(29)
    @ReturnValue(defaultPropertyThrough={mol.office.SearchScopes.class})
    mol.office.SearchScope searchScopes(
        int index);

    @VTID(30)
    mol.office.SearchFolders searchFolders();

    @VTID(30)
    @ReturnValue(defaultPropertyThrough={mol.office.SearchFolders.class})
    mol.office.ScopeFolder searchFolders(
        int index);

    @VTID(31)
    mol.office.FileTypes fileTypes();

    @VTID(31)
    @ReturnValue(defaultPropertyThrough={mol.office.FileTypes.class})
    mol.office.MsoFileType fileTypes(
        int index);

    @VTID(32)
    void refreshScopes();

}
