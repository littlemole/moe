package mol.excel  ;

import com4j.*;

@IID("{00024477-0001-0000-C000-000000000046}")
public interface IXmlNamespaces extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    mol.excel.XmlNamespace _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    mol.excel.XmlNamespace item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(12)
    int count();

    @VTID(13)
    java.lang.String value();

    @VTID(14)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(15)
    void installManifest(
        java.lang.String path,
        @MarshalAs(NativeType.VARIANT) java.lang.Object installForAllUsers);

}
