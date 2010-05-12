package mol.mshtml  ;

import com4j.*;

@IID("{3050F378-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLOptionsHolder extends Com4jObject {
    @VTID(7)
    mol.mshtml.IHTMLDocument2 document();

    @VTID(8)
    mol.mshtml.IHTMLFontNamesCollection fonts();

    @VTID(8)
    @ReturnValue(defaultPropertyThrough={mol.mshtml.IHTMLFontNamesCollection.class})
    java.lang.String fonts(
        int index);

    @VTID(9)
    void execArg(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object execArg();

    @VTID(11)
    void errorLine(
        int p);

    @VTID(12)
    int errorLine();

    @VTID(13)
    void errorCharacter(
        int p);

    @VTID(14)
    int errorCharacter();

    @VTID(15)
    void errorCode(
        int p);

    @VTID(16)
    int errorCode();

    @VTID(17)
    void errorMessage(
        java.lang.String p);

    @VTID(18)
    java.lang.String errorMessage();

    @VTID(19)
    void errorDebug(
        boolean p);

    @VTID(20)
    boolean errorDebug();

    @VTID(21)
    mol.mshtml.IHTMLWindow2 unsecuredWindowOfDocument();

    @VTID(22)
    void findText(
        java.lang.String p);

    @VTID(23)
    java.lang.String findText();

    @VTID(24)
    void anythingAfterFrameset(
        boolean p);

    @VTID(25)
    boolean anythingAfterFrameset();

    @VTID(26)
    mol.mshtml.IHTMLFontSizesCollection sizes(
        java.lang.String fontName);

    @VTID(27)
    java.lang.String openfiledlg(
        @MarshalAs(NativeType.VARIANT) java.lang.Object initFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object initDir,
        @MarshalAs(NativeType.VARIANT) java.lang.Object filter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object title);

    @VTID(28)
    java.lang.String savefiledlg(
        @MarshalAs(NativeType.VARIANT) java.lang.Object initFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object initDir,
        @MarshalAs(NativeType.VARIANT) java.lang.Object filter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object title);

    @VTID(29)
    int choosecolordlg(
        @MarshalAs(NativeType.VARIANT) java.lang.Object initColor);

    @VTID(30)
    void showSecurityInfo();

    @VTID(31)
    boolean isApartmentModel(
        mol.mshtml.IHTMLObjectElement object);

    @VTID(32)
    int getCharset(
        java.lang.String fontName);

    @VTID(33)
    java.lang.String secureConnectionInfo();

}
