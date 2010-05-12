package mol.word  ;

import com4j.*;

@IID("{000209B9-0000-0000-C000-000000000046}")
public interface _Global extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String name();

    @VTID(11)
    mol.word.Documents documents();

    @VTID(11)
    @ReturnValue(defaultPropertyThrough={mol.word.Documents.class})
    mol.word._Document documents(
        java.lang.Object index);

    @VTID(12)
    mol.word.Windows windows();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.word.Windows.class})
    mol.word.Window windows(
        java.lang.Object index);

    @VTID(13)
    mol.word._Document activeDocument();

    @VTID(14)
    mol.word.Window activeWindow();

    @VTID(15)
    mol.word.Selection selection();

    @VTID(16)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject wordBasic();

    @VTID(17)
    boolean printPreview();

    @VTID(18)
    void printPreview(
        boolean prop);

    @VTID(19)
    mol.word.RecentFiles recentFiles();

    @VTID(19)
    @ReturnValue(defaultPropertyThrough={mol.word.RecentFiles.class})
    mol.word.RecentFile recentFiles(
        int index);

    @VTID(20)
    mol.word.Template normalTemplate();

    @VTID(21)
    mol.word.System system();

    @VTID(22)
    mol.word.AutoCorrect autoCorrect();

    @VTID(23)
    mol.word.FontNames fontNames();

    @VTID(23)
    @ReturnValue(defaultPropertyThrough={mol.word.FontNames.class})
    java.lang.String fontNames(
        int index);

    @VTID(24)
    mol.word.FontNames landscapeFontNames();

    @VTID(24)
    @ReturnValue(defaultPropertyThrough={mol.word.FontNames.class})
    java.lang.String landscapeFontNames(
        int index);

    @VTID(25)
    mol.word.FontNames portraitFontNames();

    @VTID(25)
    @ReturnValue(defaultPropertyThrough={mol.word.FontNames.class})
    java.lang.String portraitFontNames(
        int index);

    @VTID(26)
    mol.word.Languages languages();

    @VTID(26)
    @ReturnValue(defaultPropertyThrough={mol.word.Languages.class})
    mol.word.Language languages(
        java.lang.Object index);

    @VTID(27)
    mol.office.Assistant assistant();

    @VTID(28)
    mol.word.FileConverters fileConverters();

    @VTID(28)
    @ReturnValue(defaultPropertyThrough={mol.word.FileConverters.class})
    mol.word.FileConverter fileConverters(
        java.lang.Object index);

    @VTID(29)
    mol.word.Dialogs dialogs();

    @VTID(29)
    @ReturnValue(defaultPropertyThrough={mol.word.Dialogs.class})
    mol.word.Dialog dialogs(
        mol.word.WdWordDialog index);

    @VTID(30)
    mol.word.CaptionLabels captionLabels();

    @VTID(30)
    @ReturnValue(defaultPropertyThrough={mol.word.CaptionLabels.class})
    mol.word.CaptionLabel captionLabels(
        java.lang.Object index);

    @VTID(31)
    mol.word.AutoCaptions autoCaptions();

    @VTID(31)
    @ReturnValue(defaultPropertyThrough={mol.word.AutoCaptions.class})
    mol.word.AutoCaption autoCaptions(
        java.lang.Object index);

    @VTID(32)
    mol.word.AddIns addIns();

    @VTID(32)
    @ReturnValue(defaultPropertyThrough={mol.word.AddIns.class})
    mol.word.AddIn addIns(
        java.lang.Object index);

    @VTID(33)
    mol.word.Tasks tasks();

    @VTID(33)
    @ReturnValue(defaultPropertyThrough={mol.word.Tasks.class})
    mol.word.Task tasks(
        java.lang.Object index);

    @VTID(34)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject macroContainer();

    @VTID(35)
    mol.office._CommandBars commandBars();

    @VTID(36)
    mol.word.SynonymInfo synonymInfo(
        java.lang.String word,
        java.lang.Object languageID);

    @VTID(37)
    mol.vba.VBE vbe();

    @VTID(38)
    mol.word.ListGalleries listGalleries();

    @VTID(38)
    @ReturnValue(defaultPropertyThrough={mol.word.ListGalleries.class})
    mol.word.ListGallery listGalleries(
        mol.word.WdListGalleryType index);

    @VTID(39)
    java.lang.String activePrinter();

    @VTID(40)
    void activePrinter(
        java.lang.String prop);

    @VTID(41)
    mol.word.Templates templates();

    @VTID(41)
    @ReturnValue(defaultPropertyThrough={mol.word.Templates.class})
    mol.word.Template templates(
        java.lang.Object index);

    @VTID(42)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject customizationContext();

    @VTID(43)
    void customizationContext(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject prop);

    @VTID(44)
    mol.word.KeyBindings keyBindings();

    @VTID(44)
    @ReturnValue(defaultPropertyThrough={mol.word.KeyBindings.class})
    mol.word.KeyBinding keyBindings(
        int index);

    @VTID(45)
    mol.word.KeysBoundTo keysBoundTo(
        mol.word.WdKeyCategory keyCategory,
        java.lang.String command,
        java.lang.Object commandParameter);

    @VTID(46)
    mol.word.KeyBinding findKey(
        int keyCode,
        java.lang.Object keyCode2);

    @VTID(47)
    mol.word.Options options();

    @VTID(48)
    mol.word.Dictionaries customDictionaries();

    @VTID(48)
    @ReturnValue(defaultPropertyThrough={mol.word.Dictionaries.class})
    mol.word.Dictionary customDictionaries(
        java.lang.Object index);

    @VTID(49)
    void statusBar(
        java.lang.String rhs);

    @VTID(50)
    boolean showVisualBasicEditor();

    @VTID(51)
    void showVisualBasicEditor(
        boolean prop);

    @VTID(52)
    boolean isObjectValid(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject object);

    @VTID(53)
    mol.word.HangulHanjaConversionDictionaries hangulHanjaDictionaries();

    @VTID(53)
    @ReturnValue(defaultPropertyThrough={mol.word.HangulHanjaConversionDictionaries.class})
    mol.word.Dictionary hangulHanjaDictionaries(
        java.lang.Object index);

    @VTID(54)
    boolean repeat(
        java.lang.Object times);

    @VTID(55)
    void ddeExecute(
        int channel,
        java.lang.String command);

    @VTID(56)
    int ddeInitiate(
        java.lang.String app,
        java.lang.String topic);

    @VTID(57)
    void ddePoke(
        int channel,
        java.lang.String item,
        java.lang.String data);

    @VTID(58)
    java.lang.String ddeRequest(
        int channel,
        java.lang.String item);

    @VTID(59)
    void ddeTerminate(
        int channel);

    @VTID(60)
    void ddeTerminateAll();

    @VTID(61)
    int buildKeyCode(
        mol.word.WdKey arg1,
        java.lang.Object arg2,
        java.lang.Object arg3,
        java.lang.Object arg4);

    @VTID(62)
    java.lang.String keyString(
        int keyCode,
        java.lang.Object keyCode2);

    @VTID(63)
    boolean checkSpelling(
        java.lang.String word,
        java.lang.Object customDictionary,
        java.lang.Object ignoreUppercase,
        java.lang.Object mainDictionary,
        java.lang.Object customDictionary2,
        java.lang.Object customDictionary3,
        java.lang.Object customDictionary4,
        java.lang.Object customDictionary5,
        java.lang.Object customDictionary6,
        java.lang.Object customDictionary7,
        java.lang.Object customDictionary8,
        java.lang.Object customDictionary9,
        java.lang.Object customDictionary10);

    @VTID(64)
    mol.word.SpellingSuggestions getSpellingSuggestions(
        java.lang.String word,
        java.lang.Object customDictionary,
        java.lang.Object ignoreUppercase,
        java.lang.Object mainDictionary,
        java.lang.Object suggestionMode,
        java.lang.Object customDictionary2,
        java.lang.Object customDictionary3,
        java.lang.Object customDictionary4,
        java.lang.Object customDictionary5,
        java.lang.Object customDictionary6,
        java.lang.Object customDictionary7,
        java.lang.Object customDictionary8,
        java.lang.Object customDictionary9,
        java.lang.Object customDictionary10);

    @VTID(65)
    void help(
        java.lang.Object helpType);

    @VTID(66)
    mol.word.Window newWindow();

    @VTID(67)
    java.lang.String cleanString(
        java.lang.String string);

    @VTID(68)
    void changeFileOpenDirectory(
        java.lang.String path);

    @VTID(69)
    float inchesToPoints(
        float inches);

    @VTID(70)
    float centimetersToPoints(
        float centimeters);

    @VTID(71)
    float millimetersToPoints(
        float millimeters);

    @VTID(72)
    float picasToPoints(
        float picas);

    @VTID(73)
    float linesToPoints(
        float lines);

    @VTID(74)
    float pointsToInches(
        float points);

    @VTID(75)
    float pointsToCentimeters(
        float points);

    @VTID(76)
    float pointsToMillimeters(
        float points);

    @VTID(77)
    float pointsToPicas(
        float points);

    @VTID(78)
    float pointsToLines(
        float points);

    @VTID(79)
    float pointsToPixels(
        float points,
        java.lang.Object fVertical);

    @VTID(80)
    float pixelsToPoints(
        float pixels,
        java.lang.Object fVertical);

    @VTID(81)
    mol.office.LanguageSettings languageSettings();

    @VTID(82)
    mol.office.AnswerWizard answerWizard();

    @VTID(83)
    mol.word.AutoCorrect autoCorrectEmail();

}
