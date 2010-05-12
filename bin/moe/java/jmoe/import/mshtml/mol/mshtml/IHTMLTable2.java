package mol.mshtml  ;

import com4j.*;

@IID("{3050F4AD-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLTable2 extends Com4jObject {
    @VTID(7)
    void firstPage();

    @VTID(8)
    void lastPage();

    @VTID(9)
    mol.mshtml.IHTMLElementCollection cells();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch,defaultPropertyThrough={mol.mshtml.IHTMLElementCollection.class})
    com4j.Com4jObject cells(
        @MarshalAs(NativeType.VARIANT) java.lang.Object name,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject moveRow(
        int indexFrom,
        int indexTo);

}
