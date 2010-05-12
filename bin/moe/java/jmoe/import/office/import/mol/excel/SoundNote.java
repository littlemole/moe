package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface SoundNote extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(117)
    java.lang.Object delete();

    @DISPID(917)
    java.lang.Object _import(
        java.lang.String filename);

    @DISPID(918)
    java.lang.Object play();

    @DISPID(919)
    java.lang.Object record();

}
