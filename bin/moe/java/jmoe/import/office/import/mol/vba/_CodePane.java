package mol.vba  ;

import com4j.*;

@IID("{0002E176-0000-0000-C000-000000000046}")
public interface _CodePane extends Com4jObject {
    @VTID(7)
    mol.vba._CodePanes collection();

    @VTID(8)
    mol.vba.VBE vbe();

    @VTID(9)
    mol.vba.Window window();

    @VTID(10)
    void getSelection(
        Holder<Integer> startLine,
        Holder<Integer> startColumn,
        Holder<Integer> endLine,
        Holder<Integer> endColumn);

    @VTID(11)
    void setSelection(
        int startLine,
        int startColumn,
        int endLine,
        int endColumn);

    @VTID(12)
    int topLine();

    @VTID(13)
    void topLine(
        int topLine);

    @VTID(14)
    int countOfVisibleLines();

    @VTID(15)
    mol.vba._CodeModule codeModule();

    @VTID(16)
    void show();

    @VTID(17)
    mol.vba.vbext_CodePaneview codePaneView();

}
