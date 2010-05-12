package mol.office  ;

import com4j.*;

@IID("{4291224C-DEFE-485B-8E69-6CF8AA85CB76}")
public interface IAssistance extends Com4jObject {
    /**
     * ShowHelp Method
     */
    @VTID(7)
    void showHelp(
        java.lang.String helpId,
        java.lang.String scope);

    /**
     * SearchHelp Method
     */
    @VTID(8)
    void searchHelp(
        java.lang.String query,
        java.lang.String scope);

    /**
     * SetDefaultContext Method
     */
    @VTID(9)
    void setDefaultContext(
        java.lang.String helpId);

    /**
     * ClearDefaultContext Method
     */
    @VTID(10)
    void clearDefaultContext(
        java.lang.String helpId);

}
