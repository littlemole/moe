package mol.office  ;

import com4j.*;

@IID("{000C0361-0000-0000-C000-000000000046}")
public interface AnswerWizardFiles extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    java.lang.String item(
        int index);

    @VTID(11)
    int count();

    @VTID(12)
    void add(
        java.lang.String fileName);

    @VTID(13)
    void delete(
        java.lang.String fileName);

}