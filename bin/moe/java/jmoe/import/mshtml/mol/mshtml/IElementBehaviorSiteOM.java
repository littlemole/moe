package mol.mshtml  ;

import com4j.*;

@IID("{3050F489-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IElementBehaviorSiteOM extends Com4jObject {
    @VTID(3)
    int registerEvent(
        @MarshalAs(NativeType.Unicode) java.lang.String pchEvent,
        int lFlags);

    @VTID(4)
    int getEventCookie(
        @MarshalAs(NativeType.Unicode) java.lang.String pchEvent);

    @VTID(5)
    void fireEvent(
        int lCookie,
        mol.mshtml.IHTMLEventObj pEventObject);

    @VTID(6)
    mol.mshtml.IHTMLEventObj createEventObject();

    @VTID(7)
    void registerName(
        @MarshalAs(NativeType.Unicode) java.lang.String pchName);

    @VTID(8)
    void registerUrn(
        @MarshalAs(NativeType.Unicode) java.lang.String pchUrn);

}
