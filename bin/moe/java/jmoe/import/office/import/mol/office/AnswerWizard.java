package mol.office  ;

import com4j.*;

@IID("{000C0360-0000-0000-C000-000000000046}")
public interface AnswerWizard extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.AnswerWizardFiles files();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.office.AnswerWizardFiles.class})
    java.lang.String files(
        int index);

    @VTID(11)
    void clearFileList();

    @VTID(12)
    void resetFileList();

}
