package mol.word  ;

import com4j.*;

@IID("{0002091E-0000-0000-C000-000000000046}")
public interface MailMergeField extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    mol.word.WdFieldType type();

    @VTID(11)
    boolean locked();

    @VTID(12)
    void locked(
        boolean prop);

    @VTID(13)
    mol.word.Range code();

    @VTID(14)
    void code(
        mol.word.Range prop);

    @VTID(15)
    mol.word.MailMergeField next();

    @VTID(16)
    mol.word.MailMergeField previous();

    @VTID(17)
    void select();

    @VTID(18)
    void copy();

    @VTID(19)
    void cut();

    @VTID(20)
    void delete();

}
