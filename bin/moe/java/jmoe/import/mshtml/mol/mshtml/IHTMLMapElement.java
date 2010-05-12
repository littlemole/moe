package mol.mshtml  ;

import com4j.*;

@IID("{3050F266-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLMapElement extends Com4jObject {
    @VTID(7)
    mol.mshtml.IHTMLAreasCollection areas();

    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLAreasCollection.class})
    com4j.Com4jObject areas(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(8)
    void name(
        java.lang.String p);

    @VTID(9)
    java.lang.String name();

}
