package mol.office  ;

import com4j.*;

@IID("{000C0353-0000-0000-C000-000000000046}")
public interface LanguageSettings extends mol.office._IMsoDispObj {
    @VTID(9)
    int languageID(
        mol.office.MsoAppLanguageID id);

    @VTID(10)
    boolean languagePreferredForEditing(
        mol.office.MsoLanguageID lid);

    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

}
