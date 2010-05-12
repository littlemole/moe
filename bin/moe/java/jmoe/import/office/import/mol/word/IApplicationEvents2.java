package mol.word  ;

import com4j.*;

@IID("{000209FE-0001-0000-C000-000000000046}")
public interface IApplicationEvents2 extends Com4jObject {
    @VTID(7)
    void startup();

    @VTID(8)
    void quit();

    @VTID(9)
    void documentChange();

    @VTID(10)
    void documentOpen(
        mol.word._Document doc);

    @VTID(11)
    void documentBeforeClose(
        mol.word._Document doc,
        Holder<Boolean> cancel);

    @VTID(12)
    void documentBeforePrint(
        mol.word._Document doc,
        Holder<Boolean> cancel);

    @VTID(13)
    void documentBeforeSave(
        mol.word._Document doc,
        Holder<Boolean> saveAsUI,
        Holder<Boolean> cancel);

    @VTID(14)
    void newDocument(
        mol.word._Document doc);

    @VTID(15)
    void windowActivate(
        mol.word._Document doc,
        mol.word.Window wn);

    @VTID(16)
    void windowDeactivate(
        mol.word._Document doc,
        mol.word.Window wn);

    @VTID(17)
    void windowSelectionChange(
        mol.word.Selection sel);

    @VTID(18)
    void windowBeforeRightClick(
        mol.word.Selection sel,
        Holder<Boolean> cancel);

    @VTID(19)
    void windowBeforeDoubleClick(
        mol.word.Selection sel,
        Holder<Boolean> cancel);

}
