package mol.mshtml  ;

import com4j.*;

@IID("{3050F23C-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLTableRow extends Com4jObject {
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
    void borderColor(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(14)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object borderColor();

    @VTID(15)
    void borderColorLight(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(16)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object borderColorLight();

    @VTID(17)
    void borderColorDark(
        @MarshalAs(NativeType.VARIANT) java.lang.Object p);

    @VTID(18)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object borderColorDark();

    @VTID(19)
    int rowIndex();

    @VTID(20)
    int sectionRowIndex();

    @VTID(21)
    mol.mshtml.IHTMLElementCollection cells();

    @VTID(21)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject cells(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(22)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject insertCell(
        int index);

    @VTID(23)
    void deleteCell(
        int index);

}
