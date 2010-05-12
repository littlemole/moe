package mol.word  ;

import com4j.*;

@IID("{00020967-0000-0000-C000-000000000046}")
public interface Bookmarks extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(8)
    int count();

    @VTID(9)
    mol.word.WdBookmarkSortBy defaultSorting();

    @VTID(10)
    void defaultSorting(
        mol.word.WdBookmarkSortBy prop);

    @VTID(11)
    boolean showHidden();

    @VTID(12)
    void showHidden(
        boolean prop);

    @VTID(13)
    mol.word._Application application();

    @VTID(14)
    int creator();

    @VTID(15)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(16)
    @DefaultMethod
    mol.word.Bookmark item(
        java.lang.Object index);

    @VTID(17)
    mol.word.Bookmark add(
        java.lang.String name,
        java.lang.Object range);

    @VTID(18)
    boolean exists(
        java.lang.String name);

}
