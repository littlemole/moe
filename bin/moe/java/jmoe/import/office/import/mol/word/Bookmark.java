package mol.word  ;

import com4j.*;

@IID("{00020968-0000-0000-C000-000000000046}")
public interface Bookmark extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String name();

    @VTID(8)
    mol.word.Range range();

    @VTID(9)
    boolean empty();

    @VTID(10)
    int start();

    @VTID(11)
    void start(
        int prop);

    @VTID(12)
    int end();

    @VTID(13)
    void end(
        int prop);

    @VTID(14)
    boolean column();

    @VTID(15)
    mol.word.WdStoryType storyType();

    @VTID(16)
    mol.word._Application application();

    @VTID(17)
    int creator();

    @VTID(18)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(19)
    void select();

    @VTID(20)
    void delete();

    @VTID(21)
    mol.word.Bookmark copy(
        java.lang.String name);

}
