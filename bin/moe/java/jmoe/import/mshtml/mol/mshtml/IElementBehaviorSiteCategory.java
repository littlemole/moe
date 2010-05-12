package mol.mshtml  ;

import com4j.*;

@IID("{3050F4EE-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IElementBehaviorSiteCategory extends Com4jObject {
    @VTID(3)
    mol.mshtml.IEnumUnknown getRelatedBehaviors(
        int lDirection,
        @MarshalAs(NativeType.Unicode) java.lang.String pchCategory);

}
