package mol.mshtml  ;

import com4j.*;

@IID("{3050F23B-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLTableSection extends Com4jObject {
    @VTID(7)
    void align(
        java.lang.String p);

    @VTID(8)
    java.lang.String align();

    @VTID(9)
    void vAlign(
        java.lang.String p);

    @VTID(10)
    java.lang.String vAlign();

    @VTID(11)
    void bgColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object bgColor();

    @VTID(13)
    mol.mshtml.IHTMLElementCollection rows();

    @VTID(13)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject rows(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject insertRow(
        int index);

    @VTID(15)
    void deleteRow(
        int index);

}
