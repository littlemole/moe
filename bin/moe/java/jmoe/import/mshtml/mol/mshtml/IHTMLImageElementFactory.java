package mol.mshtml  ;

import com4j.*;

@IID("{3050F38E-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLImageElementFactory extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    mol.mshtml.IHTMLImgElement create(
        @MarshalAs(NativeType.VARIANT) java.lang.Object width,
        @MarshalAs(NativeType.VARIANT) java.lang.Object height);

}
