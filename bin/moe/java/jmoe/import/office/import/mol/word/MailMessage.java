package mol.word  ;

import com4j.*;

@IID("{000209BA-0000-0000-C000-000000000046}")
public interface MailMessage extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    void checkName();

    @VTID(11)
    void delete();

    @VTID(12)
    void displayMoveDialog();

    @VTID(13)
    void displayProperties();

    @VTID(14)
    void displaySelectNamesDialog();

    @VTID(15)
    void forward();

    @VTID(16)
    void goToNext();

    @VTID(17)
    void goToPrevious();

    @VTID(18)
    void reply();

    @VTID(19)
    void replyAll();

    @VTID(20)
    void toggleHeader();

}
