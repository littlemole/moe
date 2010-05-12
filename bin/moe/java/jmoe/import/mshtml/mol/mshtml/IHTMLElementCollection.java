package mol.mshtml  ;

import com4j.*;

@IID("{3050F21F-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLElementCollection extends Com4jObject {
    @VTID(7)
    java.lang.String toString_();

    @VTID(8)
    void length(
        int p);

    @VTID(9)
    int length();

    @VTID(10)
    com4j.Com4jObject _newEnum();

    @VTID(11)
    @DefaultMethod
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject tags(
        @MarshalAs(NativeType.VARIANT) java.lang.Object tagName);

}
