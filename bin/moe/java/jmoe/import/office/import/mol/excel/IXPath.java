package mol.excel  ;

import com4j.*;

@IID("{0002447E-0001-0000-C000-000000000046}")
public interface IXPath extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String _Default();

    @VTID(11)
    java.lang.String value();

    @VTID(12)
    mol.excel.XmlMap map();

    @VTID(13)
    void setValue(
        mol.excel.XmlMap map,
        java.lang.String xPath,
        @MarshalAs(NativeType.VARIANT) java.lang.Object selectionNamespace,
        @MarshalAs(NativeType.VARIANT) java.lang.Object repeating);

    @VTID(14)
    void clear();

    @VTID(15)
    boolean repeating();

}
