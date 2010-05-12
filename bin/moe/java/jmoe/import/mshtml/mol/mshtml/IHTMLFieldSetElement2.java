package mol.mshtml  ;

import com4j.*;

@IID("{3050F833-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLFieldSetElement2 extends Com4jObject {
    @VTID(7)
    mol.mshtml.IHTMLFormElement form();

    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLFormElement.class})
    com4j.Com4jObject form(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
