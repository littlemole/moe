package mol.mshtml  ;

import com4j.*;

@IID("{3050F38C-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLOptionElementFactory extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    mol.mshtml.IHTMLOptionElement create(
        @MarshalAs(NativeType.VARIANT) java.lang.Object text,
        @MarshalAs(NativeType.VARIANT) java.lang.Object value,
        @MarshalAs(NativeType.VARIANT) java.lang.Object defaultSelected,
        @MarshalAs(NativeType.VARIANT) java.lang.Object selected);

}
