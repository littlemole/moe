package mol.word  ;

import com4j.*;

@IID("{54F46DC4-F6A6-48CC-BD66-46C1DDEADD22}")
public interface ContentControlListEntries extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    mol.word._Application application();

    @VTID(9)
    int creator();

    @VTID(10)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(11)
    int count();

    @VTID(12)
    void clear();

    @VTID(13)
    @DefaultMethod
    mol.word.ContentControlListEntry item(
        int index);

    @VTID(14)
    mol.word.ContentControlListEntry add(
        java.lang.String text,
        java.lang.String value,
        int index);

}
