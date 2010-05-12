package mol.word  ;

import com4j.*;

@IID("{00020922-0000-0000-C000-000000000046}")
public interface TablesOfFigures extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(11)
    int count();

    @VTID(12)
    mol.word.WdTofFormat format();

    @VTID(13)
    void format(
        mol.word.WdTofFormat prop);

    @VTID(14)
    @DefaultMethod
    mol.word.TableOfFigures item(
        int index);

    @VTID(15)
    mol.word.TableOfFigures addOld(
        mol.word.Range range,
        java.lang.Object caption,
        java.lang.Object includeLabel,
        java.lang.Object useHeadingStyles,
        java.lang.Object upperHeadingLevel,
        java.lang.Object lowerHeadingLevel,
        java.lang.Object useFields,
        java.lang.Object tableID,
        java.lang.Object rightAlignPageNumbers,
        java.lang.Object includePageNumbers,
        java.lang.Object addedStyles);

    @VTID(16)
    mol.word.Field markEntry(
        mol.word.Range range,
        java.lang.Object entry,
        java.lang.Object entryAutoText,
        java.lang.Object tableID,
        java.lang.Object level);

    @VTID(17)
    mol.word.TableOfFigures add(
        mol.word.Range range,
        java.lang.Object caption,
        java.lang.Object includeLabel,
        java.lang.Object useHeadingStyles,
        java.lang.Object upperHeadingLevel,
        java.lang.Object lowerHeadingLevel,
        java.lang.Object useFields,
        java.lang.Object tableID,
        java.lang.Object rightAlignPageNumbers,
        java.lang.Object includePageNumbers,
        java.lang.Object addedStyles,
        java.lang.Object useHyperlinks,
        java.lang.Object hidePageNumbersInWeb);

}
