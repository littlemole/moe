package mol.office  ;

import com4j.*;

@IID("{000C038A-0000-0000-C000-000000000046}")
public interface MsoDebugOptions_UTs extends mol.office._IMsoDispObj,Iterable<Com4jObject> {
    @VTID(9)
    @DefaultMethod
    mol.office.MsoDebugOptions_UT item(
        int index);

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    mol.office.MsoDebugOptions_UTs getUnitTestsInCollection(
        java.lang.String bstrCollectionName);

    @VTID(13)
    mol.office.MsoDebugOptions_UT getUnitTest(
        java.lang.String bstrCollectionName,
        java.lang.String bstrUnitTestName);

    @VTID(14)
    mol.office.MsoDebugOptions_UTs getMatchingUnitTestsInCollection(
        java.lang.String bstrCollectionName,
        java.lang.String bstrUnitTestNameFilter);

}
