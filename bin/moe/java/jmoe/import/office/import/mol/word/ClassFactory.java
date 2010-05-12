package mol.word  ;

import com4j.*;

/**
 * Defines methods to create COM objects
 */
public abstract class ClassFactory {
    private ClassFactory() {} // instanciation is not allowed


    public static mol.vba._Windows createWindows() {
        return COM4J.createInstance( mol.vba._Windows.class, "{0002E185-0000-0000-C000-000000000046}" );
    }

    public static mol.vba._LinkedWindows createLinkedWindows() {
        return COM4J.createInstance( mol.vba._LinkedWindows.class, "{0002E187-0000-0000-C000-000000000046}" );
    }

    public static mol.vba._ReferencesEvents createReferencesEvents() {
        return COM4J.createInstance( mol.vba._ReferencesEvents.class, "{0002E119-0000-0000-C000-000000000046}" );
    }

    public static mol.vba._CommandBarControlEvents createCommandBarEvents() {
        return COM4J.createInstance( mol.vba._CommandBarControlEvents.class, "{0002E132-0000-0000-C000-000000000046}" );
    }

    public static mol.vba._ProjectTemplate createProjectTemplate() {
        return COM4J.createInstance( mol.vba._ProjectTemplate.class, "{32CDF9E0-1602-11CE-BFDC-08002B2B8CDA}" );
    }

    public static mol.vba._VBProject createVBProject() {
        return COM4J.createInstance( mol.vba._VBProject.class, "{0002E169-0000-0000-C000-000000000046}" );
    }

    public static mol.vba._VBProjects createVBProjects() {
        return COM4J.createInstance( mol.vba._VBProjects.class, "{0002E101-0000-0000-C000-000000000046}" );
    }

    public static mol.vba._Components createComponents() {
        return COM4J.createInstance( mol.vba._Components.class, "{BE39F3D6-1B13-11D0-887F-00A0C90F2744}" );
    }

    public static mol.vba._VBComponents createVBComponents() {
        return COM4J.createInstance( mol.vba._VBComponents.class, "{BE39F3D7-1B13-11D0-887F-00A0C90F2744}" );
    }

    public static mol.vba._Component createComponent() {
        return COM4J.createInstance( mol.vba._Component.class, "{BE39F3D8-1B13-11D0-887F-00A0C90F2744}" );
    }

    public static mol.vba._VBComponent createVBComponent() {
        return COM4J.createInstance( mol.vba._VBComponent.class, "{BE39F3DA-1B13-11D0-887F-00A0C90F2744}" );
    }

    public static mol.vba._Properties createProperties() {
        return COM4J.createInstance( mol.vba._Properties.class, "{0002E18B-0000-0000-C000-000000000046}" );
    }

    public static mol.vba._AddIns createAddins() {
        return COM4J.createInstance( mol.vba._AddIns.class, "{DA936B63-AC8B-11D1-B6E5-00A0C90F2744}" );
    }

    public static mol.vba._CodeModule createCodeModule() {
        return COM4J.createInstance( mol.vba._CodeModule.class, "{0002E170-0000-0000-C000-000000000046}" );
    }

    public static mol.vba._CodePanes createCodePanes() {
        return COM4J.createInstance( mol.vba._CodePanes.class, "{0002E174-0000-0000-C000-000000000046}" );
    }

    public static mol.vba._CodePane createCodePane() {
        return COM4J.createInstance( mol.vba._CodePane.class, "{0002E178-0000-0000-C000-000000000046}" );
    }

    public static mol.vba._References createReferences() {
        return COM4J.createInstance( mol.vba._References.class, "{0002E17C-0000-0000-C000-000000000046}" );
    }

    public static mol.office._CustomXMLSchemaCollection createCustomXMLSchemaCollection() {
        return COM4J.createInstance( mol.office._CustomXMLSchemaCollection.class, "{000CDB0D-0000-0000-C000-000000000046}" );
    }

    public static mol.word._Global createGlobal() {
        return COM4J.createInstance( mol.word._Global.class, "{000209F0-0000-0000-C000-000000000046}" );
    }

    public static mol.word._Application createApplication() {
        return COM4J.createInstance( mol.word._Application.class, "{000209FF-0000-0000-C000-000000000046}" );
    }

    public static mol.word._Document createDocument() {
        return COM4J.createInstance( mol.word._Document.class, "{00020906-0000-0000-C000-000000000046}" );
    }

    public static mol.word._Font createFont() {
        return COM4J.createInstance( mol.word._Font.class, "{000209F5-0000-0000-C000-000000000046}" );
    }

    public static mol.word._ParagraphFormat createParagraphFormat() {
        return COM4J.createInstance( mol.word._ParagraphFormat.class, "{000209F4-0000-0000-C000-000000000046}" );
    }

    public static mol.word._OLEControl createOLEControl() {
        return COM4J.createInstance( mol.word._OLEControl.class, "{000209F2-0000-0000-C000-000000000046}" );
    }

    public static mol.word._LetterContent createLetterContent() {
        return COM4J.createInstance( mol.word._LetterContent.class, "{000209F1-0000-0000-C000-000000000046}" );
    }
}
