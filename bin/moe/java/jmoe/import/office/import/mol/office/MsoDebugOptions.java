package mol.office  ;

import com4j.*;

@IID("{000C035A-0000-0000-C000-000000000046}")
public interface MsoDebugOptions extends mol.office._IMsoDispObj {
    @VTID(9)
    int featureReports();

    @VTID(10)
    void featureReports(
        int puintFeatureReports);

    @VTID(11)
    boolean outputToDebugger();

    @VTID(12)
    void outputToDebugger(
        boolean pvarfOutputToDebugger);

    @VTID(13)
    boolean outputToFile();

    @VTID(14)
    void outputToFile(
        boolean pvarfOutputToFile);

    @VTID(15)
    boolean outputToMessageBox();

    @VTID(16)
    void outputToMessageBox(
        boolean pvarfOutputToMessageBox);

    @VTID(17)
    com4j.Com4jObject unitTestManager();

}
