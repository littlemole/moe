package mol.word  ;

import com4j.*;

@IID("{0002099C-0000-0000-C000-000000000046}")
public interface Hyperlinks extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    @DefaultMethod
    mol.word.Hyperlink item(
        java.lang.Object index);

    @VTID(13)
    mol.word.Hyperlink _Add(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject anchor,
        java.lang.Object address,
        java.lang.Object subAddress);

    @VTID(14)
    mol.word.Hyperlink add(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject anchor,
        java.lang.Object address,
        java.lang.Object subAddress,
        java.lang.Object screenTip,
        java.lang.Object textToDisplay,
        java.lang.Object target);

}
