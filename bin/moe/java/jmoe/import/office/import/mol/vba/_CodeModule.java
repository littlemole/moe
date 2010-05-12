package mol.vba  ;

import com4j.*;

@IID("{0002E16E-0000-0000-C000-000000000046}")
public interface _CodeModule extends Com4jObject {
    @VTID(7)
    mol.vba._VBComponent parent();

    @VTID(8)
    mol.vba.VBE vbe();

    @VTID(9)
    @DefaultMethod
    java.lang.String name();

    @VTID(10)
    @DefaultMethod
    void name(
        java.lang.String pbstrName);

    @VTID(11)
    void addFromString(
        java.lang.String string);

    @VTID(12)
    void addFromFile(
        java.lang.String fileName);

    @VTID(13)
    java.lang.String lines(
        int startLine,
        int count);

    @VTID(14)
    int countOfLines();

    @VTID(15)
    void insertLines(
        int line,
        java.lang.String string);

    @VTID(16)
    void deleteLines(
        int startLine,
        int count);

    @VTID(17)
    void replaceLine(
        int line,
        java.lang.String string);

    @VTID(18)
    int procStartLine(
        java.lang.String procName,
        mol.vba.vbext_ProcKind procKind);

    @VTID(19)
    int procCountLines(
        java.lang.String procName,
        mol.vba.vbext_ProcKind procKind);

    @VTID(20)
    int procBodyLine(
        java.lang.String procName,
        mol.vba.vbext_ProcKind procKind);

    @VTID(21)
    java.lang.String procOfLine(
        int line,
        Holder<mol.vba.vbext_ProcKind> procKind);

    @VTID(22)
    int countOfDeclarationLines();

    @VTID(23)
    int createEventProc(
        java.lang.String eventName,
        java.lang.String objectName);

    @VTID(24)
    boolean find(
        java.lang.String target,
        Holder<Integer> startLine,
        Holder<Integer> startColumn,
        Holder<Integer> endLine,
        Holder<Integer> endColumn,
        boolean wholeWord,
        boolean matchCase,
        boolean patternSearch);

    @VTID(25)
    mol.vba._CodePane codePane();

}
