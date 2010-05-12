package mol.office  ;

import com4j.*;

@IID("{000C0377-0000-0000-C000-000000000046}")
public interface SmartDocument extends mol.office._IMsoDispObj {
    @VTID(9)
    java.lang.String solutionID();

    @VTID(10)
    void solutionID(
        java.lang.String pbstrID);

    @VTID(11)
    java.lang.String solutionURL();

    @VTID(12)
    void solutionURL(
        java.lang.String pbstrUrl);

    @VTID(13)
    void pickSolution(
        boolean considerAllSchemas);

    @VTID(14)
    void refreshPane();

}
