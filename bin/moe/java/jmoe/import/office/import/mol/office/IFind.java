package mol.office  ;

import com4j.*;

@IID("{000C0337-0000-0000-C000-000000000046}")
public interface IFind extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String searchPath();

    @VTID(8)
    java.lang.String name();

    @VTID(9)
    boolean subDir();

    @VTID(10)
    java.lang.String title();

    @VTID(11)
    java.lang.String author();

    @VTID(12)
    java.lang.String keywords();

    @VTID(13)
    java.lang.String subject();

    @VTID(14)
    mol.office.MsoFileFindOptions options();

    @VTID(15)
    boolean matchCase();

    @VTID(16)
    java.lang.String text();

    @VTID(17)
    boolean patternMatch();

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dateSavedFrom();

    @VTID(19)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dateSavedTo();

    @VTID(20)
    java.lang.String savedBy();

    @VTID(21)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dateCreatedFrom();

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dateCreatedTo();

    @VTID(23)
    mol.office.MsoFileFindView view();

    @VTID(24)
    mol.office.MsoFileFindSortBy sortBy();

    @VTID(25)
    mol.office.MsoFileFindListBy listBy();

    @VTID(26)
    int selectedFile();

    @VTID(27)
    mol.office.IFoundFiles results();

    @VTID(27)
    @ReturnValue(defaultPropertyThrough={mol.office.IFoundFiles.class})
    java.lang.String results(
        int index);

    @VTID(28)
    int show();

    @VTID(29)
    @DefaultMethod
    void searchPath(
        java.lang.String pbstr);

    @VTID(30)
    void name(
        java.lang.String pbstr);

    @VTID(31)
    void subDir(
        boolean retval);

    @VTID(32)
    void title(
        java.lang.String pbstr);

    @VTID(33)
    void author(
        java.lang.String pbstr);

    @VTID(34)
    void keywords(
        java.lang.String pbstr);

    @VTID(35)
    void subject(
        java.lang.String pbstr);

    @VTID(36)
    void options(
        mol.office.MsoFileFindOptions penmOptions);

    @VTID(37)
    void matchCase(
        boolean retval);

    @VTID(38)
    void text(
        java.lang.String pbstr);

    @VTID(39)
    void patternMatch(
        boolean retval);

    @VTID(40)
    void dateSavedFrom(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pdatSavedFrom);

    @VTID(41)
    void dateSavedTo(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pdatSavedTo);

    @VTID(42)
    void savedBy(
        java.lang.String pbstr);

    @VTID(43)
    void dateCreatedFrom(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pdatCreatedFrom);

    @VTID(44)
    void dateCreatedTo(
        @MarshalAs(NativeType.VARIANT) java.lang.Object pdatCreatedTo);

    @VTID(45)
    void view(
        mol.office.MsoFileFindView penmView);

    @VTID(46)
    void sortBy(
        mol.office.MsoFileFindSortBy penmSortBy);

    @VTID(47)
    void listBy(
        mol.office.MsoFileFindListBy penmListBy);

    @VTID(48)
    void selectedFile(
        int pintSelectedFile);

    @VTID(49)
    void execute();

    @VTID(50)
    void load(
        java.lang.String bstrQueryName);

    @VTID(51)
    void save(
        java.lang.String bstrQueryName);

    @VTID(52)
    void delete(
        java.lang.String bstrQueryName);

    @VTID(53)
    int fileType();

    @VTID(54)
    void fileType(
        int plFileType);

}
