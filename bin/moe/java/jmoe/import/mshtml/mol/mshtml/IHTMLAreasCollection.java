package mol.mshtml  ;

import com4j.*;

@IID("{3050F383-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLAreasCollection extends Com4jObject {
    @VTID(7)
    void length(
        int p);

    @VTID(8)
    int length();

    @VTID(9)
    com4j.Com4jObject _newEnum();

    @VTID(10)
    @DefaultMethod
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject tags(
        @MarshalAs(NativeType.VARIANT) java.lang.Object tagName);

    @VTID(12)
    void add(
        mol.mshtml.IHTMLElement element,
        @MarshalAs(NativeType.VARIANT) java.lang.Object before);

    @VTID(13)
    void remove(
        int index);

}
