package mol.mshtml  ;

import com4j.*;

/**
 * Defines methods to create COM objects
 */
public abstract class ClassFactory {
    private ClassFactory() {} // instanciation is not allowed


    public static mol.mshtml.IHTMLWindow3 createHTMLWindowProxy() {
        return COM4J.createInstance( mol.mshtml.IHTMLWindow3.class, "{3050F391-98B5-11CF-BB82-00AA00BDCE0B}" );
    }

    public static mol.mshtml.IHTMLDocument3 createHTMLDocument() {
        return COM4J.createInstance( mol.mshtml.IHTMLDocument3.class, "{25336920-03F9-11CF-8FD0-00AA00686F13}" );
    }

    public static mol.mshtml.IWebBridge createScriptlet() {
        return COM4J.createInstance( mol.mshtml.IWebBridge.class, "{AE24FDAE-03C6-11D1-8B76-0080C744F389}" );
    }

    public static mol.mshtml.IHTMLPopup createHTMLPopup() {
        return COM4J.createInstance( mol.mshtml.IHTMLPopup.class, "{3050F667-98B5-11CF-BB82-00AA00BDCE0B}" );
    }
}
