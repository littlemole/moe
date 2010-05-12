package mol.word  ;

import com4j.*;

@IID("{0002096A-0000-0000-C000-000000000046}")
public interface Template extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String name();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    java.lang.String path();

    @VTID(12)
    mol.word.AutoTextEntries autoTextEntries();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.word.AutoTextEntries.class})
    mol.word.AutoTextEntry autoTextEntries(
        java.lang.Object index);

    @VTID(13)
    mol.word.WdLanguageID languageID();

    @VTID(14)
    void languageID(
        mol.word.WdLanguageID prop);

    @VTID(15)
    boolean saved();

    @VTID(16)
    void saved(
        boolean prop);

    @VTID(17)
    mol.word.WdTemplateType type();

    @VTID(18)
    java.lang.String fullName();

    @VTID(19)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject builtInDocumentProperties();

    @VTID(20)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject customDocumentProperties();

    @VTID(21)
    mol.word.ListTemplates listTemplates();

    @VTID(21)
    @ReturnValue(defaultPropertyThrough={mol.word.ListTemplates.class})
    mol.word.ListTemplate listTemplates(
        java.lang.Object index);

    @VTID(22)
    mol.word.WdLanguageID languageIDFarEast();

    @VTID(23)
    void languageIDFarEast(
        mol.word.WdLanguageID prop);

    @VTID(24)
    mol.vba._VBProject vbProject();

    @VTID(25)
    boolean kerningByAlgorithm();

    @VTID(26)
    void kerningByAlgorithm(
        boolean prop);

    @VTID(27)
    mol.word.WdJustificationMode justificationMode();

    @VTID(28)
    void justificationMode(
        mol.word.WdJustificationMode prop);

    @VTID(29)
    mol.word.WdFarEastLineBreakLevel farEastLineBreakLevel();

    @VTID(30)
    void farEastLineBreakLevel(
        mol.word.WdFarEastLineBreakLevel prop);

    @VTID(31)
    java.lang.String noLineBreakBefore();

    @VTID(32)
    void noLineBreakBefore(
        java.lang.String prop);

    @VTID(33)
    java.lang.String noLineBreakAfter();

    @VTID(34)
    void noLineBreakAfter(
        java.lang.String prop);

    @VTID(35)
    mol.word._Document openAsDocument();

    @VTID(36)
    void save();

    @VTID(37)
    int noProofing();

    @VTID(38)
    void noProofing(
        int prop);

    @VTID(39)
    mol.word.WdFarEastLineBreakLanguageID farEastLineBreakLanguage();

    @VTID(40)
    void farEastLineBreakLanguage(
        mol.word.WdFarEastLineBreakLanguageID prop);

    @VTID(41)
    mol.word.BuildingBlockEntries buildingBlockEntries();

    @VTID(41)
    @ReturnValue(defaultPropertyThrough={mol.word.BuildingBlockEntries.class})
    mol.word.BuildingBlock buildingBlockEntries(
        java.lang.Object index);

    @VTID(42)
    mol.word.BuildingBlockTypes buildingBlockTypes();

    @VTID(42)
    @ReturnValue(defaultPropertyThrough={mol.word.BuildingBlockTypes.class})
    mol.word.BuildingBlockType buildingBlockTypes(
        mol.word.WdBuildingBlockTypes index);

}
