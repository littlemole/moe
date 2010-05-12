package mol.office  ;

import com4j.*;

@IID("{000C0389-0000-0000-C000-000000000046}")
public interface MsoDebugOptions_UTManager extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    mol.office.MsoDebugOptions_UTs unitTests();

    @VTID(9)
    @ReturnValue(defaultPropertyThrough={mol.office.MsoDebugOptions_UTs.class})
    mol.office.MsoDebugOptions_UT unitTests(
        int index);

    @VTID(10)
    void notifyStartOfTestSuiteRun();

    @VTID(11)
    void notifyEndOfTestSuiteRun();

    @VTID(12)
    boolean reportErrors();

    @VTID(13)
    void reportErrors(
        boolean pfReportErrors);

}
