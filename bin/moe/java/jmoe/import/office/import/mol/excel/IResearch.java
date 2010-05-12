package mol.excel  ;

import com4j.*;

@IID("{000244AC-0001-0000-C000-000000000046}")
public interface IResearch extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object query(
        java.lang.String serviceID,
        @MarshalAs(NativeType.VARIANT) java.lang.Object queryString,
        @MarshalAs(NativeType.VARIANT) java.lang.Object queryLanguage,
        @MarshalAs(NativeType.VARIANT) java.lang.Object useSelection,
        @MarshalAs(NativeType.VARIANT) java.lang.Object launchQuery);

    @VTID(11)
    boolean isResearchService(
        java.lang.String serviceID);

    @VTID(12)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object setLanguagePair(
        int languageFrom,
        int languageTo);

}
