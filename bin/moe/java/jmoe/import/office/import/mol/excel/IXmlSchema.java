package mol.excel  ;

import com4j.*;

@IID("{00024479-0001-0000-C000-000000000046}")
public interface IXmlSchema extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.XmlNamespace namespace();

    @VTID(11)
    java.lang.String xml();

    @VTID(12)
    java.lang.String name();

}
