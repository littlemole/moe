package mol.word  ;

import com4j.*;

@IID("{00020914-0000-0000-C000-000000000046}")
public interface TablesOfContents extends Com4jObject,Iterable<Com4jObject> {
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
    mol.word.WdTocFormat format();

    @VTID(13)
    void format(
        mol.word.WdTocFormat prop);

    @VTID(14)
    @DefaultMethod
    mol.word.TableOfContents item(
        int index);

    @VTID(15)
    mol.word.TableOfContents addOld(
        mol.word.Range range,
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
    mol.word.TableOfContents add2000(
        mol.word.Range range,
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

    @VTID(18)
    mol.word.TableOfContents add(
        mol.word.Range range,
        java.lang.Object useHeadingStyles,
        java.lang.Object upperHeadingLevel,
        java.lang.Object lowerHeadingLevel,
        java.lang.Object useFields,
        java.lang.Object tableID,
        java.lang.Object rightAlignPageNumbers,
        java.lang.Object includePageNumbers,
        java.lang.Object addedStyles,
        java.lang.Object useHyperlinks,
        java.lang.Object hidePageNumbersInWeb,
        java.lang.Object useOutlineLevels);

}
