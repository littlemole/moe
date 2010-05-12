package mol.excel  ;

import com4j.*;

@IID("{0002447C-0001-0000-C000-000000000046}")
public interface IXmlMaps extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.XmlMap add(
        java.lang.String schema,
        @MarshalAs(NativeType.VARIANT) java.lang.Object rootElementName);

    @VTID(11)
    @DefaultMethod
    mol.excel.XmlMap _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    mol.excel.XmlMap item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(13)
    int count();

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

}
