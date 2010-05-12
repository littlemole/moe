package mol.mshtml  ;

import com4j.*;

@IID("{3050F211-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLOptionElement extends Com4jObject {
    @VTID(7)
    void selected(
        boolean p);

    @VTID(8)
    boolean selected();

    @VTID(9)
    void value(
        java.lang.String p);

    @VTID(10)
    java.lang.String value();

    @VTID(11)
    void defaultSelected(
        boolean p);

    @VTID(12)
    boolean defaultSelected();

    @VTID(13)
    void index(
        int p);

    @VTID(14)
    int index();

    @VTID(15)
    void text(
        java.lang.String p);

    @VTID(16)
    java.lang.String text();

    @VTID(17)
    mol.mshtml.IHTMLFormElement form();

    @VTID(17)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLFormElement.class})
    com4j.Com4jObject form(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
