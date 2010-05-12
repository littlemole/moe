package mol.mshtml  ;

import com4j.*;

@IID("{3050F662-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLEditDesigner extends Com4jObject {
    @VTID(3)
    void preHandleEvent(
        int inEvtDispId,
        mol.mshtml.IHTMLEventObj pIEventObj);

    @VTID(4)
    void postHandleEvent(
        int inEvtDispId,
        mol.mshtml.IHTMLEventObj pIEventObj);

    @VTID(5)
    void translateAccelerator(
        int inEvtDispId,
        mol.mshtml.IHTMLEventObj pIEventObj);

    @VTID(6)
    void postEditorEventNotify(
        int inEvtDispId,
        mol.mshtml.IHTMLEventObj pIEventObj);

}
